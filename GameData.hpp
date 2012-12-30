//
// GameData.hpp for ChessIA in /home/wilmot_p/PROG/C++/ChessIA
// 
// Made by WILMOT Pierre
// Login   <wilmot@epitech.net>
// 
// Started on  Mon Nov 26 22:14:07 2012 WILMOT Pierre
// Last update Thu Dec 27 18:41:54 2012 WILMOT Pierre
//

#ifndef	__GAMEDATA_HPP__
#define	__GAMEDATA_HPP__

#include	<iostream>
#include	<vector>

class	GameData
{
public:
  enum	piece
    {
      Empty,
      Pawn,
      Bishop,
      Knight,
      Rook,
      Queen,
      King
    };

  enum	team
    {
      None,
      Black,
      White
    };

  GameData();
  GameData(GameData const &g);
  ~GameData() {};

  std::ostream&					display(std::ostream &os);
  std::vector<std::pair<piece, team> >	&	operator[](int i)
  {
    return m_board[i];
  }
  std::vector<std::pair<piece, team> >	const &	operator[](int i) const
  {
    return m_board[i];
  }

  int		getDirection(team t) const;
  team		getOtherTeam(team t) const;

  void		setCase(int x, int y, piece p, team t);

protected:
  std::vector<std::vector<std::pair<piece, team> > >		m_board;
  int								m_direction[3];
};

std::ostream&					operator<<(std::ostream &os, GameData gd);

#endif	/* __GAMEDATA_HPP__ */
