//
// Rook.cpp for ChessIA in /home/wilmot_p/PROG/C++/ChessIA
// 
// Made by WILMOT Pierre
// Login   <wilmot@epitech.net>
// 
// Started on  Tue Nov 27 00:33:07 2012 WILMOT Pierre

//

#include	<iostream>
#include	"Rook.hpp"

Rook::Rook(int x, int y, GameData::team t)
  : PieceInfo(x, y, t, GameData::Rook)
{
  m_name = "Rook";

  m_directionsNb = 4;
  m_directions[0][0] = 1;
  m_directions[0][1] = 0;
  m_directions[1][0] = -1;
  m_directions[1][1] = 0;
  m_directions[2][0] = 0;
  m_directions[2][1] = 1;
  m_directions[3][0] = 0;
  m_directions[3][1] = -1;

  m_moveRange = 8;
}

Rook::~Rook()
{
}

