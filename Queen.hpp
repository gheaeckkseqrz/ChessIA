//
// Queen.hpp for ChessIA in /home/wilmot_p/PROG/C++/ChessIA
// 
// Made by WILMOT Pierre
// Login   <wilmot@epitech.net>
// 
// Started on  Tue Nov 27 00:30:06 2012 WILMOT Pierre
// Last update Thu Dec 20 19:20:50 2012 WILMOT Pierre
//

#ifndef __QUEEN_HPP__
#define __QUEEN_HPP__

#include	<iostream>
#include	"PieceInfo.hpp"

class Queen : public PieceInfo
{
 public:
  Queen(int x, int y, GameData::team t);
  ~Queen();

  std::list<GameData *>		*getSuccessors(GameData &g) const;

 private:
  int			m_directions[8][2];
};

#endif
