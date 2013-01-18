//
// Move.cpp for ChessIA in /home/wilmot_p/PROG/C++/ChessIA
// 
// Made by WILMOT Pierre
// Login   <wilmot@epitech.net>
// 
// Started on  Wed Dec 26 02:10:30 2012 WILMOT Pierre
// Last update Fri Jan 18 02:28:28 2013 WILMOT Pierre
//

#include	<iostream>
#include	"Move.hpp"

Move::Move(GameData const &g, int sx, int sy, int dx, int dy, GameData::piece p)
  :GameData(g), m_srcx(sx), m_srcy(sy), m_destx(dx), m_desty(dy), m_promotion(p)
{
  apply();
}

Move::~Move()
{
}

GameData const &				Move::getGameData() const
{
  return (*this);
}

void			Move::setGameData(GameData const &g)
{
  copy(g);
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

void			Move::setSX(int sx)
{
  m_srcx = sx;
}

void			Move::setSY(int sy)
{
  m_srcy = sy;
}

void			Move::setDX(int dx)
{
  m_destx = dx;
}

void			Move::setDY(int dy)
{
  m_desty = dy;
}


void			Move::apply()
{
  setCase(m_destx, m_desty, m_board[m_srcx][m_srcy].first, m_board[m_srcx][m_srcy].second);
  setCase(m_srcx, m_srcy, GameData::Empty, GameData::None);

  if (m_board[m_srcx][m_srcy].first == King)
    {
      m_castle[m_board[m_srcx][m_srcy].second][KingSide] = false;
      m_castle[m_board[m_srcx][m_srcy].second][QueenSide] = false;
    }
  if (((m_srcx == 0 || m_srcx == 7) && m_srcy == 0)
      ||((m_destx == 0 || m_destx == 7) && m_desty == 0))
    {
      if (getDirection(White) == 1) // Mean that white are on top of board (index 0)
	{
	  if (m_srcx == 0 || m_destx == 0)
	    m_castle[White][KingSide] = false;
	  else
	    m_castle[White][QueenSide] = false;
	}
      else // Black on top
	{
	  if (m_srcx == 0 || m_destx == 0)
	    m_castle[White][QueenSide] = false;
	  else
	    m_castle[White][KingSide] = false;
	}
    }
  if (((m_srcx == 0 || m_srcx == 7) && m_srcy == 0)
      ||((m_destx == 0 || m_destx == 7) && m_desty == 0))
    {
      if (getDirection(White) == 1) // Mean that white are on top of board (index 0)
	{
	  if (m_srcx == 0 || m_destx == 0)
	    m_castle[White][KingSide] = false;
	  else
	    m_castle[White][QueenSide] = false;
	}
      else // Black on top
	{
	  if (m_srcx == 0 || m_destx == 0)
	    m_castle[Black][QueenSide] = false;
	  else
	    m_castle[Black][KingSide] = false;
	}
    }
  else if (((m_srcx == 0 || m_srcx == 7) && m_srcy == 7)
      ||((m_destx == 0 || m_destx == 7) && m_desty == 7))
    {
      if (getDirection(White) == -1) // Mean that white are on bottom of board (index 7)
	{
	  if (m_srcx == 0 || m_destx == 0)
	    m_castle[White][QueenSide] = false;
	  else
	    m_castle[White][KingSide] = false;
	}
      else // Black on bottom
	{
	  if (m_srcx == 0 || m_destx == 0)
	    m_castle[White][KingSide] = false;
	  else
	    m_castle[White][QueenSide] = false;
	}
    }
}

void			Move::setFromLAN(std::string const &s)
{
  int	dec((s[3] == '-') ? 1 : 0);

  m_srcx = (s[0] - 'a');
  m_srcy = 7 - (s[1] - '1');
  m_destx = (s[2 + dec] - 'a');
  m_desty = 7 - (s[3 + dec] - '1');

  apply();
}

std::string		Move::getLAN() const
{
  std::string		letters = "abcdefgh";
  std::string		numbers = "12345678";
  static std::string	move = "";

  move = "";
  move += letters[getSX()];
  move += numbers[7 - getSY()];
  move += letters[getDX()];
  move += numbers[7 - getDY()];

  return (move);
}

std::ostream&					operator<<(std::ostream &os, Move const &m)
{
  os << "[(" << m.getSX() << " / " << m.getSY() << ") => (" << m.getDX() << " / " << m.getDY() << ")]";
  return (os);
}
