//
// ChessBoard.hpp for Chess IA in /home/wilmot_p/PROG/C++/[2012-11-26] - Chess IA
// 
// Made by WILMOT Pierre
// Login   <wilmot@epitech.net>
// 
// Started on  Mon Nov 26 20:43:47 2012 WILMOT Pierre
// Last update Mon Nov 26 22:52:08 2012 WILMOT Pierre
//


#ifndef	__CHESSBOARD_HPP__
#define	__CHESSBOARD_HPP__

#include	<list>
#include	<vector>
#include	<utility>
#include	"GameData.hpp"
#include	"PieceInfo.hpp"

class	ChessBoard : public GameData
{
public:

  ChessBoard();
  ~ChessBoard();

  void						initBoard();
  std::ostream&					display(std::ostream &os);
  std::list<PieceInfo>	const 			*getPieces(GameData::team t);
};

std::ostream&					operator<<(std::ostream &os, ChessBoard cb);


#endif /* __CHESSBOARD_HPP__ */
