#ifndef __KNIGHT_HPP__
#define __KNIGHT_HPP__

#include	<iostream>
#include	"PieceInfo.hpp"

class Knight : public PieceInfo
{
 public:
  Knight(int x, int y, GameData::team t);
  ~Knight();
  Knight(const Knight&);
  Knight&		operator=(const Knight&);

 private:

};

#endif
