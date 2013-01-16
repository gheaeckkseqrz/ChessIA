//
// LogManager.cpp for ChessIA in /home/wilmot_p/PROG/C++/ChessIA
// 
// Made by WILMOT Pierre
// Login   <wilmot@epitech.net>
// 
// Started on  Sun Jan 13 20:37:55 2013 WILMOT Pierre
// Last update Tue Jan 15 20:05:18 2013 WILMOT Pierre
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

void			LogManager::log(std::string const &s)
{
  m_logfile << s << std::endl;
}
