//
// PieceFactory.hpp for ChessIA in /home/wilmot_p/PROG/C++/ChessIA
// 
// Made by WILMOT Pierre
// Login   <wilmot@epitech.net>
// 
// Started on  Tue Nov 27 00:02:04 2012 WILMOT Pierre
// Last update Sun Jan 13 20:45:22 2013 WILMOT Pierre
//

#ifndef	__PIECEFACTORY_HPP__
#define	__PIECEFACTORY_HPP__

#include	"PieceInfo.hpp"
#include	"Pawn.hpp"
#include	"Bishop.hpp"
#include	"Knight.hpp"
#include	"Rook.hpp"
#include	"King.hpp"
#include	"Queen.hpp"

class	PieceFactory
{
public:
  ~PieceFactory();
  static PieceFactory	*getInstance();

  PieceInfo	*create(int x, int y, GameData::team t, GameData::piece p);

private:
  PieceInfo	*createPawn(int x, int y, GameData::team t);
  PieceInfo	*createBishop(int x, int y, GameData::team t);
  PieceInfo	*createKnight(int x, int y, GameData::team t);
  PieceInfo	*createRook(int x, int y, GameData::team t);
  PieceInfo	*createKing(int x, int y, GameData::team t);
  PieceInfo	*createQueen(int x, int y, GameData::team t);


private:
  PieceFactory();
  typedef PieceInfo *(PieceFactory::* funcPtr)(int x, int y, GameData::team t);
  static PieceFactory	*m_alreadyCreated;
  funcPtr		array[7];
};

#endif	/* __PIECEFACTORY_HPP__ */
