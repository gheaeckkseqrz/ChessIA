//
// RatedMove.hpp for ChessIA in /home/wilmot_p/PROG/C++/ChessIA
// 
// Made by WILMOT Pierre
// Login   <wilmot@epitech.net>
// 
// Started on  Thu Dec 27 17:52:00 2012 WILMOT Pierre
// Last update Sat Dec 29 16:32:45 2012 WILMOT Pierre
//

#ifndef __RATEDMOVE_HPP__
#define __RATEDMOVE_HPP__

#include	<iostream>
#include	"Move.hpp"

class RatedMove : public Move
{
public:
  RatedMove(Move *m, float score = 0);
  ~RatedMove();

  Move	const &	getMove();

  void		setScore(float s);
  float		getScore() const;

private:
  float		m_score;
};

bool		operator<(RatedMove const &a, RatedMove const &b);

#endif
