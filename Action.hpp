//
// Action.hpp for ChessIA in /home/wilmot_p/PROG/C++/ChessIA
// 
// Made by WILMOT Pierre
// Login   <wilmot@epitech.net>
// 
// Started on  Sun Jan 13 22:41:18 2013 WILMOT Pierre
// Last update Tue Jan 15 20:11:09 2013 WILMOT Pierre
//

#ifndef __ACTION_HPP__
#define __ACTION_HPP__

#include	<iostream>

class Action
{
public:
  enum e_type
    {
      IsReady,
      Position,
      Go
    };

public:
  Action(e_type t, std::string const &s = "");
  ~Action();

  e_type		getType() const;
  std::string		getFen() const;

private:
  e_type		m_type;
  std::string		m_fenString;
};

#endif
