//
// GameData.hpp for ChessIA in /home/wilmot_p/PROG/C++/ChessIA
// 
// Made by WILMOT Pierre
// Login   <wilmot@epitech.net>
// 
// Started on  Mon Nov 26 22:14:07 2012 WILMOT Pierre
// Last update Wed Dec 12 15:23:55 2012 WILMOT Pierre
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

  const std::string	pieceNames[7] =
  {
    "Empty",
    "Pawn",
    "Bishop",
    "Knight",
    "Rook",
    "Queen",
    "King"
  };

  enum	team
    {
      None,
      Black,
      White
    };

  GameData() {};
  virtual ~GameData() {};

  std::vector<std::pair<piece, team> >	const &	operator[](int i) const
  {
    return m_board[i];
  }

  int		getDirection(team t) const;
  team		getOtherTeam(team t) const;

protected:
  std::vector<std::vector<std::pair<piece, team> > >		m_board;
  int								m_direction[3];
};

#endif	/* __GAMEDATA_HPP__ */
