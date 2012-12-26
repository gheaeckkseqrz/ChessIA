//
// Move.hpp for ChessIA in /home/wilmot_p/PROG/C++/ChessIA
// 
// Made by WILMOT Pierre
// Login   <wilmot@epitech.net>
// 
// Started on  Wed Dec 26 02:10:25 2012 WILMOT Pierre
// Last update Wed Dec 26 23:08:37 2012 WILMOT Pierre
//

#ifndef __MOVE_HPP__
#define __MOVE_HPP__

#include	<iostream>
#include	"GameData.hpp"

class Move : public GameData
{
public:
  /* p is used to specify the piece to use in case of pawn promotion */
  Move(GameData g, int sx, int sy, int dx, int dy, GameData::piece p = GameData::Empty);
  ~Move();

  int		getSX() const;
  int		getSY() const;
  int		getDX() const;
  int		getDY() const;

private:
  int			m_srcx;
  int			m_srcy;
  int			m_destx;
  int			m_desty;
  GameData::piece	m_promotion;

};

#endif
