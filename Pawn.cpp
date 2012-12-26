//
// Pawn.cpp for ChessIA in /home/wilmot_p/PROG/C++/ChessIA
// 
// Made by WILMOT Pierre
// Login   <wilmot@epitech.net>
// 
// Started on  Tue Nov 27 00:30:50 2012 WILMOT Pierre

//

#include	<iostream>
#include	"Pawn.hpp"

Pawn::Pawn(int x, int y, GameData::team t)
  : PieceInfo(x, y, t, GameData::Pawn)
{
  m_name = "Pawn";
}

Pawn::~Pawn()
{
}

bool				Pawn::startPosition(GameData &g) const
{
  if ((g.getDirection(m_team) == 1 && m_y == 1)
      || (g.getDirection(m_team) == -1 && m_y == 6))
    return (true);
  return (false);
}

std::list<Move *>		*Pawn::getSuccessors(GameData &g) const
{
  std::list<Move *>	*successorStateList = NULL;
  Move			*successorState;

  successorStateList = new std::list<Move *>();

  std::cout << "Get Pawn Successor" << std::endl;

  if (caseIsValid(m_x, m_y + g.getDirection(m_team))
      && g[m_x][m_y + g.getDirection(m_team)].first == GameData::Empty)
    {
      std::cout << "Pawn can move one case ahead" << std::endl;
      successorState = new Move(g, m_x, m_y, m_x, m_y + g.getDirection(m_team));
      // successorState->setCase(m_x, m_y, GameData::Empty, GameData::None);
      // successorState->setCase(m_x, m_y + g.getDirection(m_team), m_piece, m_team);
      successorStateList->push_back(successorState);
      successorState = NULL;
      if (caseIsValid(m_x, m_y + (2 * g.getDirection(m_team)))
	  && g[m_x][m_y + (2 * g.getDirection(m_team))].first == GameData::Empty
	  && startPosition(g))
	{
	  std::cout << "Pawn can move two case ahead" << std::endl;
	  successorState = new Move(g, m_x, m_y, m_x, m_y + (2 * g.getDirection(m_team)));
	  // successorState->setCase(m_x, m_y, GameData::Empty, GameData::None);
	  // successorState->setCase(m_x, m_y + (2 * g.getDirection(m_team)), m_piece, m_team);
	  successorStateList->push_back(successorState);
	  successorState = NULL;
	}
    }
  if (caseIsValid(m_x - 1, m_y + g.getDirection(m_team))
      && g[m_x - 1][m_y + g.getDirection(m_team)].second != GameData::None
      && g[m_x - 1][m_y + g.getDirection(m_team)].second != m_team)
    {
      std::cout << "Pawn can move left" << std::endl;
      successorState = new Move(g, m_x, m_y, m_x - 1, m_y + g.getDirection(m_team));
      // successorState->setCase(m_x, m_y, GameData::Empty, GameData::None);
      // successorState->setCase(m_x - 1, m_y + g.getDirection(m_team), m_piece, m_team);
      successorStateList->push_back(successorState);
      successorState = NULL;
    }
  if (caseIsValid(m_x + 1, m_y + g.getDirection(m_team))
      && g[m_x + 1][m_y + g.getDirection(m_team)].second != GameData::None
      && g[m_x + 1][m_y + g.getDirection(m_team)].second != m_team)
    {
      std::cout << "Pawn can move right" << std::endl;
      successorState = new Move(g, m_x, m_y, m_x + 1, m_y + g.getDirection(m_team));
      // successorState->setCase(m_x, m_y, GameData::Empty, GameData::None);
      // successorState->setCase(m_x + 1, m_y + g.getDirection(m_team), m_piece, m_team);
      successorStateList->push_back(successorState);
      successorState = NULL;
    }
  return (successorStateList);
}

