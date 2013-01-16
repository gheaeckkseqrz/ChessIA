//
// LogManager.hpp for ChessIA in /home/wilmot_p/PROG/C++/ChessIA
// 
// Made by WILMOT Pierre
// Login   <wilmot@epitech.net>
// 
// Started on  Sun Jan 13 20:37:49 2013 WILMOT Pierre
// Last update Wed Jan 16 15:57:08 2013 WILMOT Pierre
//

#ifndef __LOGMANAGER_HPP__
#define __LOGMANAGER_HPP__

#include	<iostream>
#include	<fstream>
#include	"Mutex.hpp"

#define		LOGFILE_PATH	"/home/wilmot_p/ChessIAlogfile"

class LogManager
{
public:
  enum e_source
    {
      UCI,
      UCI_IN,
      UCI_OUT,
      MinMax,
      ChessBoard,
      Unknow
    };

public:
  ~LogManager();
  static LogManager	*getInstance();

  void			log(std::string const &s, e_source source = Unknow);

private:
  LogManager();

private:
  static LogManager	*m_alreadyCreated;
  std::ofstream		m_logfile;
  int			m_colorCodes[Unknow + 1];
  Mutex			m_mutex;
};

#endif
