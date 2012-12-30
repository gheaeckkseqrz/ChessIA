//
// MinMax.hpp for ChessIA in /home/wilmot_p/PROG/C++/ChessIA
// 
// Made by WILMOT Pierre
// Login   <wilmot@epitech.net>
// 
// Started on  Wed Dec 26 01:53:02 2012 WILMOT Pierre
// Last update Sun Dec 30 20:33:46 2012 WILMOT Pierre
//

#ifndef __MINMAX_HPP__
#define __MINMAX_HPP__

#include	<iostream>
#include	"ChessBoard.hpp"
#include	"RatedMove.hpp"

class MinMax
{
 public:
  MinMax(int depth = 2);
  ~MinMax();

  void		setDepth(int d);

  Move	const &	getBestMove(ChessBoard const & current, GameData::team t) const;

 private:

  RatedMove	*min(GameData const &gd, GameData::team t, int d) const;
  RatedMove	*max(GameData const &gd, GameData::team t, int d) const;

  float		eval(GameData const &gd, GameData::team t) const;

  int		m_depth;
  float		m_piecesVal[7];
};

#endif
