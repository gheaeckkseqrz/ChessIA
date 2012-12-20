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

Queen::~Queen()
{
}

std::list<GameData *>		*Queen::getSuccessors(GameData &g) const
{
  std::cout << "Get Queen Successor" << std::endl;
  for (int a(0) ; a < 8 ; ++a)
    {
      for (int i(0) ; i < 8 ; ++i)
	{
	  for (int j(0) ; j < 8 ; ++j)
	    {
	      if (caseIsValid(m_x + (i * m_directions[a][0]), m_y + (j * m_directions[a][1])))
		{
		  if (g[m_x + (i * m_directions[a][0])][m_y + (j * m_directions[a][1])].first == GameData::Empty)
		    {
		      std::cout << "Queen can Reach " << i << "/" << j << std::endl;
		    }
		  else if (g[m_x + (i * m_directions[a][0])][m_y + (j * m_directions[a][1])].second == g.getOtherTeam(m_team))
		    {
		      std::cout << "Queen can Reach " << i << "/" << j << " (capture)" << std::endl;
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
  return (NULL);
}
