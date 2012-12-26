//
// GameData.cpp for ChessIA in /home/wilmot_p/PROG/C++/ChessIA
// 
// Made by WILMOT Pierre
// Login   <wilmot@epitech.net>
// 
// Started on  Wed Dec 12 12:09:32 2012 WILMOT Pierre
// Last update Wed Dec 26 01:18:29 2012 WILMOT Pierre
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
}

GameData::GameData(GameData &g)
{
  for (int i(0) ; i < 8 ; ++i)
    {
      m_board.push_back(std::vector<std::pair<piece, team> >());
      for (int j(0) ; j < 8 ; ++j)
	{
	  m_board[i].push_back(std::pair<piece, team>(g[i][j].first, g[i][j].second));
	}
    }
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

std::ostream&					GameData::display(std::ostream &os)
{
  for (int i(0) ; i < 8 ; ++i)
    {
      for (int j(0) ; j < 8 ; ++j)
	os << "+---";
      os << "+" << std::endl;
      for (int j(0) ; j < 8 ; ++j)
	{
	  os << "|";
	  if (m_board[j][i].second == White)
	    os << "\033[34m";
	  if (m_board[j][i].second == Black)
	    os << "\033[33m";
	  switch (m_board[j][i].first)
	    {
	    case None:
	      os << "   ";
	      break;
	    case Pawn:
	      os << " P ";
	      break;
	    case Bishop:
	      os << " B ";
	      break;
	    case Knight:
	      os << " k ";
	      break;
	    case Rook:
	      os << " R ";
	      break;
	    case Queen:
	      os << " Q ";
	      break;
	    case King:
	      os << " K ";
	      break;
	    default:
	      break;
	    }
	  os << "\033[0m";
	}
      os << "|" << std::endl;
    }
  for (int j(0) ; j < 8 ; ++j)
    os << "+---";
  os << "+" << std::endl;

  return os;
}

std::ostream&		operator<<(std::ostream &os, GameData gd)
{
  return gd.display(os);
}
