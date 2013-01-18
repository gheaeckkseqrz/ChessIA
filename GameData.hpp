//
// GameData.hpp for ChessIA in /home/wilmot_p/PROG/C++/ChessIA
// 
// Made by WILMOT Pierre
// Login   <wilmot@epitech.net>
// 
// Started on  Mon Nov 26 22:14:07 2012 WILMOT Pierre
// Last update Fri Jan 18 02:15:37 2013 WILMOT Pierre
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
      Empty = 0,
      Pawn = 1,
      Bishop = 2,
      Knight = 3,
      Rook = 4,
      Queen = 5,
      King = 6
    };

  std::string	m_pieceNames[9] =
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

  enum	e_castle
    {
      KingSide = 0,
      QueenSide = 1
    };

  enum	e_row
    {
      R1 = 7,
      R2 = 6,
      R3 = 5,
      R4 = 4,
      R5 = 3,
      R6 = 2,
      R7 = 1,
      R8 = 0
    };

  enum	e_col
    {
      CA = 0,
      CB = 1,
      CC = 2,
      CD = 3,
      CE = 4,
      CF = 5,
      CG = 6,
      CH = 7
    };

  GameData();
  GameData(GameData const &g);
  ~GameData() {};

  void		copy(GameData const &g);

  std::ostream&					display(std::ostream &os) const;
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

  std::string	getFenString() const;

  void		setCase(int x, int y, piece p, team t);

protected:
  std::vector<std::vector<std::pair<piece, team> > >		m_board;
  int								m_direction[3];
  bool								m_castle[3][2];
};

std::ostream&					operator<<(std::ostream &os, GameData const &gd);

#endif	/* __GAMEDATA_HPP__ */
