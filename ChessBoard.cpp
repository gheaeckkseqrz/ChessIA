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
  for (int i(0) ; i < 8 ; ++i)
    {
      m_board.push_back(std::vector<std::pair<piece, team> >());
      for (int j(0) ; j < 8 ; ++j)
	{
	  m_board[i].push_back(std::pair<piece, team>(Empty, None));
	}
    }
  initBoard();
}

ChessBoard::~ChessBoard()
{
  getPieces(None);
}

void						ChessBoard::initBoard()
{
  std::cout << "Initialising Game" << std::endl;

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

std::list<PieceInfo *> const			*ChessBoard::getPieces(GameData::team t)
{
  static std::list<PieceInfo *>		*l(NULL);
  PieceFactory				*f;

  if (t == None)
    {
      if (l != NULL)
	{
	  delete l;
	  l = NULL;
	}
      return NULL;
    }

  f = PieceFactory::getInstance();
  (void)f;

  if (l == NULL)
    l = new std::list<PieceInfo *>;

  for (int i(0) ; i < 8 ; ++i)
    {
      for (int j(0) ; j < 8 ; ++j)
	{
	  if (m_board[i][j].second == t)
	    {
	      l->push_back(f->create(i, j, t, m_board[i][j].first));
	      std::cout << i << " // " << j << " || "
			<< GameData::pieceNames[m_board[i][j].first] << std::endl;;
	    }
	}
    }
  return l;
}

std::ostream&					ChessBoard::display(std::ostream &os)
{
  os << "Displaying Board" << std::endl;

  for (int i(0) ; i < 8 ; ++i)
    {
      for (int j(0) ; j < 8 ; ++j)
	os << "+---";
      os << "+" << std::endl;
      for (int j(0) ; j < 8 ; ++j)
	{
	  switch (m_board[j][i].first)
	    {
	    case None:
	      os << "|   ";
	      break;
	    case Pawn:
	      os << "| P ";
	      break;
	    case Bishop:
	      os << "| B ";
	      break;
	    case Knight:
	      os << "| k ";
	      break;
	    case Rook:
	      os << "| R ";
	      break;
	    case Queen:
	      os << "| Q ";
	      break;
	    case King:
	      os << "| K ";
	      break;
	    default:
	      break;
	    }
	}
      os << "|" << std::endl;
    }
  for (int j(0) ; j < 8 ; ++j)
    os << "+---";
  os << "+" << std::endl;

  return os;
}

std::ostream&		operator<<(std::ostream &os, ChessBoard cb)
{
  return cb.display(os);
}
