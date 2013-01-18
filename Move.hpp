//
// Move.hpp for ChessIA in /home/wilmot_p/PROG/C++/ChessIA
// 
// Made by WILMOT Pierre
// Login   <wilmot@epitech.net>
// 
// Started on  Wed Dec 26 02:10:25 2012 WILMOT Pierre
// Last update Fri Jan 18 02:19:32 2013 WILMOT Pierre
//

#ifndef __MOVE_HPP__
#define __MOVE_HPP__

#include	<iostream>
#include	"GameData.hpp"

class Move : public GameData
{
public:
  /* p is used to specify the piece to use in case of pawn promotion */
  Move(GameData const &g, int sx, int sy, int dx, int dy, GameData::piece p = GameData::Empty);
  ~Move();

  GameData const &	getGameData() const;
  void			setGameData(GameData const &g);

  int		getSX() const;
  int		getSY() const;
  int		getDX() const;
  int		getDY() const;
  void		setSX(int sx);
  void		setSY(int sy);
  void		setDX(int dx);
  void		setDY(int dy);
  void		apply();

  std::string	getLAN() const;

  // LAN : Long algebraic notation
  void		setFromLAN(std::string const &s);

private:
  int			m_srcx;
  int			m_srcy;
  int			m_destx;
  int			m_desty;
  GameData::piece	m_promotion;
};

std::ostream&					operator<<(std::ostream &os, Move const &m);

#endif
