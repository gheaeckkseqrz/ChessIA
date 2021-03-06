//
// LogManager.cpp for ChessIA in /home/wilmot_p/PROG/C++/ChessIA
// 
// Made by WILMOT Pierre
// Login   <wilmot@epitech.net>
// 
// Started on  Sun Jan 13 20:37:55 2013 WILMOT Pierre
// Last update Fri Jan 18 02:27:44 2013 WILMOT Pierre
//

#include	<iostream>
#include	"LogManager.hpp"

LogManager		*LogManager::m_alreadyCreated = NULL;

LogManager::LogManager()
  :m_logfile(LOGFILE_PATH, std::ios::out)
{
  if (!m_logfile)
    {
      std::cerr << "Can't open " << LOGFILE_PATH << std::endl;
    }
  log("New instance of LogManager");

  m_colorCodes[UCI] = 32;
  m_colorCodes[UCI_IN] = 33;
  m_colorCodes[UCI_OUT] = 34;
  m_colorCodes[MinMax] = 35;
  m_colorCodes[ChessBoard] = 31;
  m_colorCodes[Unknow] = 0;
}

LogManager::~LogManager()
{
  m_logfile.close();
  m_alreadyCreated = NULL;
}

LogManager		*LogManager::getInstance()
{
  if (m_alreadyCreated)
    return (m_alreadyCreated);
  else
    {
      m_alreadyCreated = new LogManager();
      return (m_alreadyCreated);
    }
}

void			LogManager::log(std::string const &s, e_source source)
{
  m_mutex.lock();
  m_logfile << "\033[" << m_colorCodes[source] << "m" << s << "\033[0m" << std::endl;
  //  std::cout << "\033[" << m_colorCodes[source] << "m" << s << "\033[0m" << std::endl;
  m_mutex.unlock();
}
