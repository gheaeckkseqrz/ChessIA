//
// Knight.cpp for ChessIA in /home/wilmot_p/PROG/C++/ChessIA
// 
// Made by WILMOT Pierre
// Login   <wilmot@epitech.net>
// 
// Started on  Tue Nov 27 00:33:13 2012 WILMOT Pierre

//

#include	<iostream>
#include	"Knight.hpp"

Knight::Knight(int x, int y, GameData::team t)
  : PieceInfo(x, y, t, GameData::Knight)
{
  m_name = "Knight";
  m_directions[0][0] = 1;
  m_directions[0][1] = -2;
  m_directions[1][0] = -1;
  m_directions[1][1] = -2;
  m_directions[2][0] = 2;
  m_directions[2][1] = -1;
  m_directions[3][0] = 2;
  m_directions[3][1] = 1;
  m_directions[4][0] = 1;
  m_directions[4][1] = 2;
  m_directions[5][0] = -1;
  m_directions[5][1] = 2;
  m_directions[6][0] = -2;
  m_directions[6][1] = 1;
  m_directions[7][0] = -2;
  m_directions[7][1] = -1;
}

Knight::~Knight()
{
}

std::list<Move *>		*Knight::getSuccessors(GameData const &g) const
{
  std::list<Move *>	*successorStateList = NULL;
  Move			*successorState;

  successorStateList = new std::list<Move *>();

  int	dest_x;
  int	dest_y;

  for (int a(0) ; a < 8 ; ++a)
    {
      dest_x = m_x + m_directions[a][0];
      dest_y = m_y + m_directions[a][1];
      if (caseIsValid(dest_x, dest_y))
	{
	  if (g[dest_x][dest_y].first == GameData::Empty)
	    {
	      successorState = new Move(g, m_x, m_y, dest_x, dest_y);
	      successorStateList->push_back(successorState);
	      successorState = NULL;
	    }
	}
    }
  return (successorStateList);
}
