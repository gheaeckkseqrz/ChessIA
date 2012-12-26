//
// Pawn.hpp for ChessIA in /home/wilmot_p/PROG/C++/ChessIA
// 
// Made by WILMOT Pierre
// Login   <wilmot@epitech.net>
// 
// Started on  Tue Nov 27 00:27:50 2012 WILMOT Pierre
// Last update Wed Dec 26 23:24:08 2012 WILMOT Pierre
//

#ifndef __PAWN_HPP__
#define __PAWN_HPP__

#include	<iostream>
#include	"PieceInfo.hpp"

class Pawn : public PieceInfo
{
 public:
  Pawn(int x, int y, GameData::team t);
  ~Pawn();

  virtual std::list<Move *>		*getSuccessors(GameData &g) const;
  bool					startPosition(GameData &g) const;

 private:
};

#endif /* __PAWN_HPP__ */
