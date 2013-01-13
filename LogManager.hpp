//
// LogManager.hpp for ChessIA in /home/wilmot_p/PROG/C++/ChessIA
// 
// Made by WILMOT Pierre
// Login   <wilmot@epitech.net>
// 
// Started on  Sun Jan 13 20:37:49 2013 WILMOT Pierre
// Last update Sun Jan 13 21:03:31 2013 WILMOT Pierre
//

#ifndef __LOGMANAGER_HPP__
#define __LOGMANAGER_HPP__

#include	<iostream>
#include	<fstream>

#define		LOGFILE_PATH	"log/logfile"

class LogManager
{
public:
  ~LogManager();
  static LogManager	*getInstance();

  void			log(std::string const &s);

private:
  LogManager();

private:
  static LogManager	*m_alreadyCreated;
  std::ofstream		m_logfile;
};

#endif
