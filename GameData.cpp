//
// GameData.cpp for ChessIA in /home/wilmot_p/PROG/C++/ChessIA
// 
// Made by WILMOT Pierre
// Login   <wilmot@epitech.net>
// 
// Started on  Wed Dec 12 12:09:32 2012 WILMOT Pierre
// Last update Wed Dec 12 15:25:09 2012 WILMOT Pierre
//

#include	"GameData.hpp"

int			GameData::getDirection(team t) const
{
  return (m_direction[t]);
}

GameData::team		GameData::getOtherTeam(team t) const
{
  if (t == White)
    return (Black);
  return (White);
}
