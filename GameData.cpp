//
// GameData.cpp for ChessIA in /home/wilmot_p/PROG/C++/ChessIA
// 
// Made by WILMOT Pierre
// Login   <wilmot@epitech.net>
// 
// Started on  Wed Dec 12 12:09:32 2012 WILMOT Pierre
// Last update Wed Dec 12 12:15:38 2012 WILMOT Pierre
//

#include	"GameData.hpp"

int		GameData::getDirection(team t) const
{
  return (m_direction[t]);
}