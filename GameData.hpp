//
// GameData.hpp for ChessIA in /home/wilmot_p/PROG/C++/ChessIA
// 
// Made by WILMOT Pierre
// Login   <wilmot@epitech.net>
// 
// Started on  Mon Nov 26 22:14:07 2012 WILMOT Pierre
// Last update Mon Nov 26 22:59:09 2012 WILMOT Pierre
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

protected:
  std::vector<std::vector<std::pair<piece, team> > >		m_board;

};

#endif	/* __GAMEDATA_HPP__ */
