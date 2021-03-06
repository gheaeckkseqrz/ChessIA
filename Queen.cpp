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
  m_name = "Queen";

  m_directionsNb = 8;
  m_directions[0][0] = 1;
  m_directions[0][1] = 1;
  m_directions[1][0] = 1;
  m_directions[1][1] = -1;
  m_directions[2][0] = -1;
  m_directions[2][1] = 1;
  m_directions[3][0] = -1;
  m_directions[3][1] = -1;

  m_directions[4][0] = 1;
  m_directions[4][1] = 0;
  m_directions[5][0] = -1;
  m_directions[5][1] = 0;
  m_directions[6][0] = 0;
  m_directions[6][1] = 1;
  m_directions[7][0] = 0;
  m_directions[7][1] = -1;

  m_moveRange = 8;
}

Queen::~Queen()
{
}

