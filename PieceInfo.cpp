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
  std::cout << "Get " << m_name << " Successor" << std::endl;
  for (int a(0) ; a < m_directionsNb  ; ++a)
    {
      for (int i(0) ; i < m_moveRange ; ++i)
	{
	  for (int j(0) ; j < m_moveRange ; ++j)
	    {
	      if (caseIsValid(m_x + (i * m_directions[a][0]), m_y + (j * m_directions[a][1])))
		{
		  if (g[m_x + (i * m_directions[a][0])][m_y + (j * m_directions[a][1])].first == GameData::Empty)
		    {
		      std::cout << m_name << " can Reach " << i << "/" << j << std::endl;
		    }
		  else if (g[m_x + (i * m_directions[a][0])][m_y + (j * m_directions[a][1])].second == g.getOtherTeam(m_team))
		    {
		      std::cout << m_name << " can Reach " << i << "/" << j << " (capture)" << std::endl;
		      i = 8;
		      j = 8;
		    }
		  else
		    {
		      i = 8;
		      j = 8;
		    }
		}
	      else
		{
		  i = 8;
		  j = 8;
		}
	    }
	}
    }
  return NULL;
}

bool			PieceInfo::caseIsValid(int x, int y) const
{
  if (x >= 0 && x < 8 && y >= 0 && y < 8)
    return (true);
  return (false);
}
