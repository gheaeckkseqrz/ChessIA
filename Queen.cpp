//
// Queen.cpp for ChessIA in /home/wilmot_p/PROG/C++/ChessIA
// 
// Made by WILMOT Pierre
// Login   <wilmot@epitech.net>
// 
// Started on  Tue Nov 27 00:32:41 2012 WILMOT Pierre

//

#include	<iostream>
#include	"Queen.hpp"

Queen::Queen(int x, int y, GameData::team t)
  : PieceInfo(x, y, t, GameData::Queen)
{
}

Queen::~Queen()
{
}
