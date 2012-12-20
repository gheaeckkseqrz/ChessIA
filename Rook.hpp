//
// Rook.hpp for ChessIA in /home/wilmot_p/PROG/C++/ChessIA
// 
// Made by WILMOT Pierre
// Login   <wilmot@epitech.net>
// 
// Started on  Tue Nov 27 00:29:12 2012 WILMOT Pierre
// Last update Thu Dec 20 21:25:00 2012 WILMOT Pierre
//

#ifndef __ROOK_HPP__
#define __ROOK_HPP__

#include	<iostream>
#include	"PieceInfo.hpp"

class Rook : public PieceInfo
{
 public:
  Rook(int x, int y, GameData::team t);
  ~Rook();

 private:
};

#endif
