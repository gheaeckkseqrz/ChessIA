//
// ChessBoard.cpp for Chess IA in /home/wilmot_p/PROG/C++/[2012-11-26] - Chess IA
// 
// Made by WILMOT Pierre
// Login   <wilmot@epitech.net>
// 
// Started on  Mon Nov 26 20:51:48 2012 WILMOT Pierre

//

#include	<iostream>
#include	"ChessBoard.hpp"
#include	"PieceFactory.hpp"

ChessBoard::ChessBoard()
{
  initBoard();
}

ChessBoard::ChessBoard(GameData const &gd)
  :GameData(gd)
{
}

ChessBoard::~ChessBoard()
{
}

GameData const &				ChessBoard::getGameData() const
{
  return (*this);
}

void						ChessBoard::initBoard()
{
  for (int i(0) ; i < 8 ; ++i)
    {
      m_board[i][1] = std::pair<piece, team>(Pawn, Black);
      m_board[i][6] = std::pair<piece, team>(Pawn, White);
    }
  m_board[0][0] = std::pair<piece, team>(Rook, Black);
  m_board[1][0] = std::pair<piece, team>(Knight, Black);
  m_board[2][0] = std::pair<piece, team>(Bishop, Black);
  m_board[3][0] = std::pair<piece, team>(Queen, Black);
  m_board[4][0] = std::pair<piece, team>(King, Black);
  m_board[5][0] = std::pair<piece, team>(Bishop, Black);
  m_board[6][0] = std::pair<piece, team>(Knight, Black);
  m_board[7][0] = std::pair<piece, team>(Rook, Black);

  for (int i(0) ; i < 8 ; ++i)
    {
      m_board[i][7] = std::pair<piece, team>(m_board[i][0].first, White);
    }
  m_direction[Black] = 1;
  m_direction[White] = -1;
}

std::list<PieceInfo *> const			*ChessBoard::getPieces(GameData::team t) const
{
  std::list<PieceInfo *>		*l(NULL);
  PieceFactory				*f = PieceFactory::getInstance();

  l = new std::list<PieceInfo *>; // Alloc 1

  for (int i(0) ; i < 8 ; ++i)
    {
      for (int j(0) ; j < 8 ; ++j)
	{
	  if (m_board[i][j].second == t)
	    l->push_back(f->create(i, j, t, m_board[i][j].first)); // ! new alloc 9
	}
    }
  return (l);
}

std::list<Move *> const			*ChessBoard::getSuccessors(GameData::team t) const
{
  const std::list<PieceInfo *>	*l;
  l = getPieces(t);

  std::list<Move *>	*successorStateList = NULL;
  std::list<Move *>	*successorStateListTmp = NULL;
  successorStateList = new std::list<Move *>(); // Alloc 2

  for (std::list<PieceInfo *>::const_iterator it = l->begin() ; it != l->end() ; ++it)
    {
      successorStateListTmp = (*it)->getSuccessors(getGameData());
      successorStateList->splice(successorStateList->end(), *successorStateListTmp);
      delete successorStateListTmp; // Un-alloc 7
      delete *it; // Un-alloc 9
    }
  delete l; // Un-alloc 1
  return (successorStateList);
}

std::ostream&		operator<<(std::ostream &os, ChessBoard cb)
{
  return cb.display(os);
}
