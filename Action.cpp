//
// Action.cpp for ChessIA in /home/wilmot_p/PROG/C++/ChessIA
// 
// Made by WILMOT Pierre
// Login   <wilmot@epitech.net>
// 
// Started on  Sun Jan 13 22:41:22 2013 WILMOT Pierre

//

#include	<iostream>
#include	"Action.hpp"

Action::Action(e_type t, std::string const &s)
  :m_type(t), m_fenString(s)
{
}

Action::~Action()
{
}

Action::e_type			Action::getType() const
{
  return (m_type);
}

std::string		Action::getFen() const
{
  return (m_fenString);
}
