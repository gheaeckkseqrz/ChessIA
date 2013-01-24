//
// UCI.cpp for ChessIA in /home/wilmot_p/PROG/C++/ChessIA
// 
// Made by WILMOT Pierre
// Login   <wilmot@epitech.net>
// 
// Started on  Thu Jan  3 20:14:06 2013 WILMOT Pierre
// Last update Thu Jan 24 10:40:44 2013 WILMOT Pierre
//

#include	<iostream>
#include	<sstream>
#include	"UCI.hpp"
#include	"LogManager.hpp"
#include	"ChessBoard.hpp"

UCI::UCI(std::string const & name, std::string const & author)
  :m_name(name), m_author(author)
{
  // TODO : Encapsuler la VarCond
  m_varcond = PTHREAD_COND_INITIALIZER;
  threadIt();
}

UCI::~UCI()
{
}

bool		UCI::registerEngine() const
{
  std::cout << "id name " << m_name << std::endl;
  LogManager::getInstance()->log("Sent [id name "+m_name+"]", LogManager::UCI_OUT);
  std::cout << "id author " << m_author << std::endl;
  LogManager::getInstance()->log("Sent [id author "+m_author+"]", LogManager::UCI_OUT);
  std::cout << "uciok" << std::endl;
  LogManager::getInstance()->log("Sent [uciok]", LogManager::UCI_OUT);
  return true;
}

void		UCI::setDebug(std::string const &s)
{
  std::stringstream	ss(s);
  std::string		word;

  ss >> word;
  ss >> word;

  if (word == "on")
    {
      LogManager::getInstance()->log("Set debug On", LogManager::UCI);
      std::cout << "info Debug set on" << std::endl;
      // TODO : Set debug on
    }
  if (word == "off")
    {
      LogManager::getInstance()->log("Set debug Off", LogManager::UCI);
      // TODO : Set debug off
    }

}

void		UCI::isReady()
{
  m_actionQueue.push(new Action(Action::IsReady, "isReady"));
  LogManager::getInstance()->log("Pushed a isready action to the queue", LogManager::UCI);
}

void		UCI::position(std::string const &s)
{
  std::string		fen;

  fen = s.substr(9, s.size() - 9);
  if (fen == "startpos")
    {
      fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
      m_actionQueue.push(new Action(Action::Position, fen));
      LogManager::getInstance()->log("Pushing position "+fen, LogManager::UCI);
    }
  else
    {
      if (fen.compare(0, 15, "startpos moves ") == 0) // glchess position format
	{
	  fen = generateFenFromStarposMoves(fen);
	  m_actionQueue.push(new Action(Action::Position, fen));
	}
      LogManager::getInstance()->log("Pushing position "+fen, LogManager::UCI);
    }
}

Action		*UCI::getAction()
{
  Action	*a;

  m_actionQueueMutex.lock();
  if (m_actionQueue.empty())
    {
      // TODO : Encapsuler la VarCond
      pthread_cond_wait (&m_varcond, m_actionQueueMutex.getCMutex());
    }
  else
    {
      a = m_actionQueue.back();
      m_actionQueue.pop();
      m_actionQueueMutex.unlock();
      LogManager::getInstance()->log("Returning action "+a->getFen(), LogManager::UCI);
      return a;
    }
  m_actionQueueMutex.unlock();
  return (NULL);
}

void		UCI::sendMove(Move const &m) const
{
  LogManager::getInstance()->log("Sending Move "+m.getLAN(), LogManager::UCI_OUT);
  std::cout << "bestmove " << m.getLAN() << std::endl;
}

void		UCI::go(std::string const &s)
{
  (void)s;
  m_actionQueue.push(new Action(Action::Go, s));
  LogManager::getInstance()->log("Pushed a go action to the queue", LogManager::UCI);
}

std::string	UCI::generateFenFromStarposMoves(std::string const &s) const
{
  ChessBoard		cb;
  Move			m(GameData(), 3, 3, 3, 3);
  std::string		move;
  std::stringstream	ss(s);

  LogManager::getInstance()->log("Generating FEN for "+s, LogManager::UCI);

  ss >> move;
  ss >> move;
  ss >> move;
  while (move != "")
    {
      m.setFromLAN(move);
      cb.applyMove(m);
      move = "";
      ss >> move;
    }
  LogManager::getInstance()->log("Result is "+cb.getFenString(), LogManager::UCI);
  return (cb.getFenString());
}

int		UCI::threadEntryPoint()
{
  std::string	guimsg;

  while (!mustQuit())
    {
      std::getline(std::cin, guimsg);
      // TODO : Encapsuler la VarCond
      pthread_cond_signal(&m_varcond);
      LogManager::getInstance()->log("Got ["+guimsg+"] from GUI", LogManager::UCI_IN);

      if (guimsg == "quit")
	setMustQuit(true);
      else if (guimsg == "uci")
	registerEngine();
      else if (guimsg.compare(0, 6, "debug ") == 0)
	setDebug(guimsg);
      else if (guimsg == "isready")
	isReady();
      else if (guimsg.compare(0, 9, "position ") == 0)
	position(guimsg);
      else if (guimsg.compare(0, 3, "go ") == 0)
	go(guimsg);
    }
  return (0);
}
