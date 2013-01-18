//
// GameData.cpp for ChessIA in /home/wilmot_p/PROG/C++/ChessIA
// 
// Made by WILMOT Pierre
// Login   <wilmot@epitech.net>
// 
// Started on  Wed Dec 12 12:09:32 2012 WILMOT Pierre
// Last update Fri Jan 18 02:27:18 2013 WILMOT Pierre
//

#include	"GameData.hpp"

GameData::GameData()
{
  for (int i(0) ; i < 8 ; ++i)
    {
      m_board.push_back(std::vector<std::pair<piece, team> >());
      for (int j(0) ; j < 8 ; ++j)
	{
	  m_board[i].push_back(std::pair<piece, team>(Empty, None));
	}
    }
  m_direction[GameData::White] = -1;
  m_direction[GameData::Black] = 1;
  m_castle[GameData::White][KingSide] = true;
  m_castle[GameData::Black][KingSide] = true;
  m_castle[GameData::White][QueenSide] = true;
  m_castle[GameData::Black][QueenSide] = true;
}

GameData::GameData(GameData const  &g)
{
  copy(g);
}

void			GameData::copy(GameData const &g)
{
  for (int i(0) ; i < 8 ; ++i)
    {
      m_board.push_back(std::vector<std::pair<piece, team> >());
      for (int j(0) ; j < 8 ; ++j)
	{
	  m_board[i].push_back(std::pair<piece, team>(g[i][j].first, g[i][j].second));
	}
    }
  m_direction[GameData::White] = -1;
  m_direction[GameData::Black] = 1;
}

int			GameData::getDirection(team t) const
{
  return (m_direction[t]);
}

GameData::team		GameData::getOtherTeam(team t) const
{
  if (t == White)
    return (Black);
  return (White);
}

void			GameData::setCase(int x, int y, piece p, team t)
{
  m_board[x][y] = std::pair<piece, team>(p, t);
}

std::string		GameData::getFenString() const
{
  static std::string	result;
  char			pieceLetter[] = "pbnrqk";
  char			numbers[] = "012345678";
  int			empty(0);

  result = "";
  for (int i(R8) ; i <= R1 ; ++i)
    {
      for (int j(CA) ; j <= CH ; ++j)
	{
	  if (m_board[j][i].second != None && empty > 0)
	    {
	      result += numbers[empty];
	      empty = 0;
	    }
	  if (m_board[j][i].second == White)
	    result += (pieceLetter[m_board[j][i].first - 1] + ('A' - 'a'));
	  else if (m_board[j][i].second == Black)
	    result += pieceLetter[m_board[j][i].first - 1];
	  else
	    empty++;
	}
      if (empty > 0)
	{
	  result += numbers[empty];
	  empty = 0;
	}
      if (i < 7)
	result += '/';
    }
  return (result);
}

std::ostream&					GameData::display(std::ostream &os) const
{
  std::string	letters("abcdefgh ");

  for (int j(0) ; j < 9 ; ++j)
    os << "+---";
  os << "+" << std::endl;
  for (int j(0) ; j < 9 ; ++j)
    os << "| " << letters[j] << " ";
  os << "|" << std::endl;
  for (int i(R8) ; i <= R1 ; ++i) // Parcours en hauteur
    {
      for (int j(0) ; j < 9 ; ++j)
	os << "+---";
      os << "+" << std::endl;
      for (int j(CA) ; j <= CH ; ++j) // Parcour en largeur
	{
	  os << "|";
	  if (m_board[j][i].second == White)
	    os << "\033[33m"; // BLUE
	  if (m_board[j][i].second == Black)
	    os << "\033[34m"; // YELLOW
	  switch (m_board[j][i].first)
	    {
	    case None:
	      os << "   ";
	      break;
	    case Pawn:
	      os << " ♟ ";
	      break;
	    case Bishop:
	      os << " ♝ ";
	      break;
	    case Knight:
	      os << " ♞ ";
	      break;
	    case Rook:
	      os << " ♜ ";
	      break;
	    case Queen:
	      os << " ♛ ";
	      break;
	    case King:
	      os << " ♚ ";
	      break;
	    default:
	      break;
	    }
	  os << "\033[0m";
	}
      os << "| " << 8 - i << " |" << std::endl;
    }
  for (int j(0) ; j < 9 ; ++j)
    os << "+---";
  os << "+" << std::endl;

  return os;
}

std::ostream&		operator<<(std::ostream &os, GameData const &gd)
{
  return gd.display(os);
}
