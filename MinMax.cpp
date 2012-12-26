//
// MinMax.cpp for ChessIA in /home/wilmot_p/PROG/C++/ChessIA
// 
// Made by WILMOT Pierre
// Login   <wilmot@epitech.net>
// 
// Started on  Wed Dec 26 01:52:52 2012 WILMOT Pierre

//

#include	<iostream>
#include	"MinMax.hpp"

MinMax::MinMax()
{
}

MinMax::~MinMax()
{
}

Move	const &	MinMax::getBestMove(GameData const & current) const
{
  GameData	n(current);

  static Move ret(n, 0, 0, 0, 0);
  (void) current;

  return (ret);
}
