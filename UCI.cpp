//
// UCI.cpp for ChessIA in /home/wilmot_p/PROG/C++/ChessIA
// 
// Made by WILMOT Pierre
// Login   <wilmot@epitech.net>
// 
// Started on  Thu Jan  3 20:14:06 2013 WILMOT Pierre
// Last update Wed Jan 16 02:07:07 2013 WILMOT Pierre
//

#include	<iostream>
#include	<sstream>
#include	"UCI.hpp"
#include	"LogManager.hpp"
#include	"ChessBoard.hpp"

UCI::UCI(std::string const & name, std::string const & author)
  :m_name(name), m_author(author)
{
  threadIt();
}

UCI::~UCI()
{
}

bool		UCI::registerEngine() const
{
  std::cout << "id name " << m_name << std::endl;
  LogManager::getInstance()->log("Sent [id name "+m_name+"]");
  std::cout << "id author " << m_author << std::endl;
  LogManager::getInstance()->log("Sent [id author "+m_author+"]");
  std::cout << "uciok" << std::endl;
  LogManager::getInstance()->log("Sent [uciok]");
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
      LogManager::getInstance()->log("Set debug On");
      std::cout << "info Debug set on" << std::endl;
      // Set debug on
    }
  if (word == "off")
    {
      LogManager::getInstance()->log("Set debug Off");
      // Set debug off
    }

}

void		UCI::isReady()
{
  m_actionQueue.push(new Action(Action::IsReady, "isReady"));
  LogManager::getInstance()->log("Pushed a isready action to the queue");
}

void		UCI::position(std::string const &s)
{
  std::string		fen;

  fen = s.substr(9, s.size() - 9);
  if (fen == "startpos")
    {
      fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
      m_actionQueue.push(new Action(Action::Position, fen));
      LogManager::getInstance()->log("Pushing position "+fen);
    }
  else
    {
      if (fen.compare(0, 15, "startpos moves ") == 0) // glchess position format
	{
	  fen = generateFenFromStarposMoves(fen);
	  m_actionQueue.push(new Action(Action::Position, fen));
	}
      LogManager::getInstance()->log("Pushing position "+fen);
    }
}

Action		*UCI::getAction()
{
  Action	*a;

  m_actionQueueMutex.lock();
  if (m_actionQueue.empty())
    {
      m_actionQueueMutex.unlock();
      // LogManager::getInstance()->log("No action to return");
      return (NULL);
    }
  a = m_actionQueue.back();
  m_actionQueue.pop();
  m_actionQueueMutex.unlock();
  LogManager::getInstance()->log("Returning action "+a->getFen());
  return a;
}

void		UCI::sendMove(Move const &m) const
{
  std::string	letters = "abcdefgh";
  std::string	numbers = "12345678";
  std::string	move = "";

  move += letters[m.getSX()];
  move += numbers[7 - m.getSY()];
  move += letters[m.getDX()];
  move += numbers[7 - m.getDY()];

  LogManager::getInstance()->log("Sending Move "+move);
  std::cout << "bestmove " << move << std::endl;
}

void		UCI::go(std::string const &s)
{
  (void)s;
  m_actionQueue.push(new Action(Action::Go, s));
  LogManager::getInstance()->log("Pushed a go action to the queue");
}

std::string	UCI::generateFenFromStarposMoves(std::string const &s) const
{
  ChessBoard		cb;
  Move			m(GameData(), 3, 3, 3, 3);
  std::string		move;
  std::stringstream	ss(s);

  LogManager::getInstance()->log("Generating FEN for "+s);

  ss >> move;
  ss >> move;
  ss >> move;
  while (move != "")
    {
      m.setFromLAN(move);
      cb.applyMove(m);
      std::cout << "Applying Move " << move << std::endl;
      std::cout << cb << std::endl;
      move = "";
      ss >> move;
    }
  LogManager::getInstance()->log("Result is "+cb.getFenString());
  return (cb.getFenString());
}

int		UCI::threadEntryPoint()
{
  std::string	guimsg;

  while (!mustQuit())
    {
      std::getline(std::cin, guimsg);
      LogManager::getInstance()->log("Got ["+guimsg+"] from GUI");

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
