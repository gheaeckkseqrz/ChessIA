//
// PieceInfo.cpp for ChessIA in /home/wilmot_p/PROG/C++/ChessIA
// 
// Made by WILMOT Pierre
// Login   <wilmot@epitech.net>
// 
// Started on  Mon Nov 26 22:25:16 2012 WILMOT Pierre

//

#include	"PieceInfo.hpp"

PieceInfo::PieceInfo(int x, int y, GameData::team t, GameData::piece p)
  :m_x(x), m_y(y), m_team(t), m_piece(p)
{
}

int			PieceInfo::getX() const
{
  return (m_x);
}

int			PieceInfo::getY() const
{
  return (m_y);
}

GameData::team		PieceInfo::getTeam() const
{
  return (m_team);
}


GameData::piece		PieceInfo::getPiece() const
{
  return (m_piece);
}

std::list<GameData *>	*PieceInfo::getSuccessors(GameData & g) const
{
  std::cerr << "getSuccessors had been called from a PieceInfos, it should only be called from derivaterd classes" << std::endl;
  (void)g;
  return NULL;
}

bool			PieceInfo::caseIsValid(int x, int y) const
{
  if (x > 0 && x < 8 && y > 0 && y < 8)
    return (true);
  return (false);
}
