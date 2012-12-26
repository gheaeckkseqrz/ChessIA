//
// PieceInfo.hpp for ChessIA in /home/wilmot_p/PROG/C++/ChessIA
// 
// Made by WILMOT Pierre
// Login   <wilmot@epitech.net>
// 
// Started on  Mon Nov 26 22:18:52 2012 WILMOT Pierre
// Last update Wed Dec 26 23:18:51 2012 WILMOT Pierre
//

#ifndef	__PIECEINFO_HPP__
#define	__PIECEINFO_HPP__

#include	<list>
#include	"GameData.hpp"
#include	"Move.hpp"

class	PieceInfo
{
public:

  PieceInfo(int x, int y, GameData::team t, GameData::piece p);
  ~PieceInfo() {};

  int				getX() const;
  int				getY() const;
  GameData::team		getTeam() const;
  GameData::piece		getPiece() const;
  virtual std::list<Move *>	*getSuccessors(GameData &g) const;
  bool				caseIsValid(int x, int y) const;

protected:
  PieceInfo();
  int				m_x;
  int				m_y;
  int				m_directions[8][2];
  int				m_directionsNb;
  int				m_moveRange;
  GameData::team		m_team;
  GameData::piece		m_piece;
  std::string			m_name;
};

#endif /* __PIECEINFO_HPP__ */
