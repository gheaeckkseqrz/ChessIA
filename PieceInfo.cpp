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

std::string			PieceInfo::getName() const
{
  return (m_name);
}

std::list<Move *>	*PieceInfo::getSuccessors(GameData const & g) const
{
  std::list<Move *>	*successorStateList = NULL;
  Move			*successorState = NULL;

  successorStateList = new std::list<Move *>(); // Alloc 7

  for (int a(0) ; a < m_directionsNb  ; ++a)
    {
      for (int i(1) ; i < m_moveRange ; ++i)
	{
	  if (caseIsValid(m_x + (i * m_directions[a][0]), m_y + (i * m_directions[a][1])))
	    {
	      if (g[m_x + (i * m_directions[a][0])][m_y + (i * m_directions[a][1])].first == GameData::Empty
		  || g[m_x + (i * m_directions[a][0])][m_y + (i * m_directions[a][1])].second == g.getOtherTeam(m_team))
		{
		  successorState = new Move(g, m_x, m_y, m_x + (i * m_directions[a][0]), m_y + (i * m_directions[a][1])); // Alloc 8
		  successorStateList->push_back(successorState);
		  successorState = NULL;
		}
	      else
		i = 8;
	    }
	  else
	    {
	      i = 8;
	    }
	}
    }
  return (successorStateList);
}

bool			PieceInfo::caseIsValid(int x, int y) const
{
  if (x >= 0 && x < 8 && y >= 0 && y < 8)
    return (true);
  return (false);
}
