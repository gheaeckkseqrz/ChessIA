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
#include	"LogManager.hpp"

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

void						ChessBoard::setFromFen(std::string const &s)
{
  int		x(0);
  int		y(0);
  int		empty(0);

  LogManager::getInstance()->log("Setting from FEN "+s, LogManager::ChessBoard);

  for (unsigned int i(0) ; i < s.size() ; ++i)
    {
      switch (s[i])
	{
	case 'p':
	  setCase(x, y, Pawn, Black);
	  break;
	case 'b':
	  setCase(x, y, Bishop, Black);
	  break;
	case 'n':
	  setCase(x, y, Knight, Black);
	  break;
	case 'r':
	  setCase(x, y, Rook, Black);
	  break;
	case 'q':
	  setCase(x, y, Queen, Black);
	  break;
	case 'k':
	  setCase(x, y, King, Black);
	  break;
	case 'P':
	  setCase(x, y, Pawn, White);
	  break;
	case 'B':
	  setCase(x, y, Bishop, White);
	  break;
	case 'N':
	  setCase(x, y, Knight, White);
	  break;
	case 'R':
	  setCase(x, y, Rook, White);
	  break;
	case 'K':
	  setCase(x, y, King, White);
	  break;
	case 'Q':
	  setCase(x, y, Queen, White);
	  break;
	case '/':
	  x = -1;
	  y++;
	  break;
	}
      if (s[i] >= '0' && s[i] <= '8')
	{
	  for (empty = (s[i] - '0') ; empty > 0 ; --empty)
	    {
	      setCase(x, y, Empty, None);
	      x++;
	    }
	}
      else
	x++;
      if (x >= 7 && y >= 7)
	break;
    }
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

void					ChessBoard::applyMove(Move const &m)
{
  setCase(m.getDX(), m.getDY(), m_board[m.getSX()][m.getSY()].first, m_board[m.getSX()][m.getSY()].second);
  setCase(m.getSX(), m.getSY(), GameData::Empty, GameData::None);

  // TODO : NEED TO ADD CASTLING MANAGEMENT (cf Move::apply())
}

std::ostream&		operator<<(std::ostream &os, ChessBoard cb)
{
  return cb.display(os);
}
