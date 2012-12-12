//
// King.cpp for ChessIA in /home/wilmot_p/PROG/C++/ChessIA
// 
// Made by WILMOT Pierre
// Login   <wilmot@epitech.net>
// 
// Started on  Tue Nov 27 00:32:50 2012 WILMOT Pierre

//

#include	<iostream>
#include	"King.hpp"

King::King(int x, int y, GameData::team t)
  : PieceInfo(x, y, t, GameData::King)
{
}

King::~King()
{
}
