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
}

King::~King()
{
}

std::list<GameData *>		*King::getSuccessors(GameData &g) const
{
  std::cout << "Get King Successor" << std::endl;
  for (int a(0) ; a < 8 ; ++a)
    {
      if (caseIsValid(m_x + m_directions[a][0], m_y + m_directions[a][1]))
	{
	  if (g[m_x + m_directions[a][0]][m_y + m_directions[a][1]].first == GameData::Empty)
	    {
	      std::cout << "King can Reach " << m_x + m_directions[a][0] << "/" << m_x + m_directions[a][1] << std::endl;
	    }
	  else if (g[m_x + m_directions[a][0]][m_y + m_directions[a][1]].second == g.getOtherTeam(m_team))
	    {
	      std::cout << "King can Reach " << m_x + m_directions[a][0] << "/" << m_x + m_directions[a][1] << " (capture)" << std::endl;
	    }
	}
    }
  return (NULL);
}

