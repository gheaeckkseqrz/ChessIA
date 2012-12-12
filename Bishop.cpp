//
// Bishop.cpp for ChessIA in /home/wilmot_p/PROG/C++/ChessIA
// 
// Made by WILMOT Pierre
// Login   <wilmot@epitech.net>
// 
// Started on  Tue Nov 27 00:33:00 2012 WILMOT Pierre

//

#include	<iostream>
#include	"Bishop.hpp"

Bishop::Bishop(int x, int y, GameData::team t)
  : PieceInfo(x, y, t, GameData::Bishop)
{
}

Bishop::~Bishop()
{
}
