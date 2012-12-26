//
// Move.cpp for ChessIA in /home/wilmot_p/PROG/C++/ChessIA
// 
// Made by WILMOT Pierre
// Login   <wilmot@epitech.net>
// 
// Started on  Wed Dec 26 02:10:30 2012 WILMOT Pierre
// Last update Wed Dec 26 23:34:22 2012 WILMOT Pierre
//

#include	<iostream>
#include	"Move.hpp"

Move::Move(GameData g, int sx, int sy, int dx, int dy, GameData::piece p)
  :GameData(g), m_srcx(sx), m_srcy(sy), m_destx(dx), m_desty(dy), m_promotion(p)
{
  setCase(dx, dy, m_board[sx][sy].first, m_board[sx][sy].second);
  setCase(sx, sy, GameData::Empty, GameData::None);
}

Move::~Move()
{
}


int			Move::getSX() const
{
  return (m_srcx);
}

int			Move::getSY() const
{
  return (m_srcy);
}

int			Move::getDX() const
{
  return (m_destx);
}

int			Move::getDY() const
{
  return (m_desty);
}
