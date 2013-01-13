//
// UCI.hpp for ChessIA in /home/wilmot_p/PROG/C++/ChessIA
// 
// Made by WILMOT Pierre
// Login   <wilmot@epitech.net>
// 
// Started on  Thu Jan  3 20:14:12 2013 WILMOT Pierre
// Last update Sun Jan 13 20:23:47 2013 WILMOT Pierre
//

#ifndef __UCI_HPP__
#define __UCI_HPP__

#include	<iostream>
#include	"Threadable.hpp"

class UCI : public Threadable
{
 public:
  UCI(std::string const & name, std::string const & author);
  ~UCI();

  bool			registerEngine() const;
  int			threadEntryPoint();
  void			setDebug(std::string const & s);
  void			setDebug(bool b);
  void			isReady() const;

 private:
  std::string		m_name;
  std::string		m_author;
};

#endif
