//
// Knight.hpp for ChessIA in /home/wilmot_p/PROG/C++/ChessIA
// 
// Made by WILMOT Pierre
// Login   <wilmot@epitech.net>
// 
// Started on  Wed Dec 26 23:27:08 2012 WILMOT Pierre
// Last update Wed Dec 26 23:27:37 2012 WILMOT Pierre
//

#ifndef __KNIGHT_HPP__
#define __KNIGHT_HPP__

#include	<iostream>
#include	"PieceInfo.hpp"
#include	"Move.hpp"

class Knight : public PieceInfo
{
 public:
  Knight(int x, int y, GameData::team t);
  ~Knight();

  std::list<Move *>		*getSuccessors(GameData &g) const;

 private:
  int			m_directions[8][2];
};

#endif
