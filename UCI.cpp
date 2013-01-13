//
// UCI.cpp for ChessIA in /home/wilmot_p/PROG/C++/ChessIA
// 
// Made by WILMOT Pierre
// Login   <wilmot@epitech.net>
// 
// Started on  Thu Jan  3 20:14:06 2013 WILMOT Pierre
// Last update Sun Jan 13 21:06:22 2013 WILMOT Pierre
//

#include	<iostream>
#include	<sstream>
#include	"UCI.hpp"
#include	"LogManager.hpp"

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
  std::cout << "id author " << m_author << std::endl;
  std::cout << "uciok" << std::endl;
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
      std::cout << "info Debug set on" << std::endl;
      // Set debug on
    }
  if (word == "off")
    {
      // Set debug off
    }

}

void		UCI::isReady() const
{
  std::cout << "readyok" << std::endl;
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
      if (guimsg.compare(0, 6, "debug ") == 0)
	setDebug(guimsg);
      if (guimsg == "isready")
	isReady();
    }
  return (0);
}
