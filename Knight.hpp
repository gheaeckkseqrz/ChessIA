#ifndef __KNIGHT_HPP__
#define __KNIGHT_HPP__

#include	<iostream>
#include	"PieceInfo.hpp"

class Knight : public PieceInfo
{
 public:
  Knight(int x, int y, GameData::team t);
  ~Knight();

  std::list<GameData *>		*getSuccessors(GameData &g) const;

 private:
  int			m_directions[8][2];
};

#endif
