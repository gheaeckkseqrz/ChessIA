//
// PieceFactory.cpp for ChessIA in /home/wilmot_p/PROG/C++/ChessIA
// 
// Made by WILMOT Pierre
// Login   <wilmot@epitech.net>
// 
// Started on  Tue Nov 27 00:18:08 2012 WILMOT Pierre
// Last update Tue Nov 27 10:47:31 2012 WILMOT Pierre
//

#include	"PieceFactory.hpp"

PieceFactory		*PieceFactory::m_alreadyCreated = NULL;

PieceFactory::~PieceFactory()
{
  m_alreadyCreated = NULL;
}

PieceFactory		*PieceFactory::getInstance()
{
  if (m_alreadyCreated)
    return (m_alreadyCreated);
  else
    {
      m_alreadyCreated = new PieceFactory();
      return (m_alreadyCreated);
    }
}

PieceFactory::PieceFactory()
{
  array[GameData::Pawn] = &PieceFactory::createPawn;
  array[GameData::Bishop] = &PieceFactory::createBishop;
  array[GameData::Knight] = &PieceFactory::createKnight;
  array[GameData::Rook] = &PieceFactory::createRook;
  array[GameData::King] = &PieceFactory::createKing;
  array[GameData::Queen] = &PieceFactory::createQueen;
  m_alreadyCreated = this;
}

PieceInfo		*PieceFactory::create(int x, int y, GameData::team t, GameData::piece p)
{
  return (((*this).*array[p])(x, y, t));
}

PieceInfo		*PieceFactory::createPawn(int x, int y, GameData::team t)
{
  return (new Pawn(x, y, t));
}

PieceInfo		*PieceFactory::createBishop(int x, int y, GameData::team t)
{
  return (new Bishop(x, y, t));
}

PieceInfo		*PieceFactory::createKnight(int x, int y, GameData::team t)
{
  return (new Knight(x, y, t));
}

PieceInfo		*PieceFactory::createRook(int x, int y, GameData::team t)
{
  return (new Rook(x, y, t));
}

PieceInfo		*PieceFactory::createKing(int x, int y, GameData::team t)
{
  return (new King(x, y, t));
}

PieceInfo		*PieceFactory::createQueen(int x, int y, GameData::team t)
{
  return (new Queen(x, y, t));
}
