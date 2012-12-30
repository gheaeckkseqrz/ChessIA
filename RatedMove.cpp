//
// RatedMove.cpp for ChessIA in /home/wilmot_p/PROG/C++/ChessIA
// 
// Made by WILMOT Pierre
// Login   <wilmot@epitech.net>
// 
// Started on  Thu Dec 27 17:52:51 2012 WILMOT Pierre
// Last update Sat Dec 29 16:33:24 2012 WILMOT Pierre
//

#include	<iostream>
#include	"RatedMove.hpp"

RatedMove::RatedMove(Move *m, float score)
  :Move(*m), m_score(score)
{
}

RatedMove::~RatedMove()
{
}

Move const &	RatedMove::getMove()
{
  return (*this);
}

void		RatedMove::setScore(float s)
{
  m_score = s;
}

float		RatedMove::getScore() const
{
  return (m_score);
}

bool		operator<(RatedMove const &a, RatedMove const &b)
{
  return (a.getScore() < b.getScore());
}
