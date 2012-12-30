//
// MinMax.cpp for ChessIA in /home/wilmot_p/PROG/C++/ChessIA
// 
// Made by WILMOT Pierre
// Login   <wilmot@epitech.net>
// 
// Started on  Wed Dec 26 01:52:52 2012 WILMOT Pierre

//

#include	<iostream>
#include	<algorithm>
#include	<boost/iterator/indirect_iterator.hpp>
#include	"MinMax.hpp"


MinMax::MinMax(int depth)
  :m_depth(depth)
{
  m_piecesVal[GameData::Pawn] = 1;
  m_piecesVal[GameData::Bishop] = 3;
  m_piecesVal[GameData::Knight] = 3;
  m_piecesVal[GameData::Rook] = 5;
  m_piecesVal[GameData::Queen] = 9;
  m_piecesVal[GameData::King] = 0;

  std::cout << "Depth is " << m_depth << std::endl;

}

MinMax::~MinMax()
{
}

void		MinMax::setDepth(int d)
{
  m_depth = d;
}

Move	const &	MinMax::getBestMove(ChessBoard const & current, GameData::team t) const
{
  (void)t;
  GameData		n(current);
  RatedMove		*m;

  m = max(current.getGameData(), t, m_depth);
  static Move	ret(n, m->getSX(), m->getSY(), m->getDX(), m->getDY());
  return (ret);
}

RatedMove	*MinMax::min(GameData const &gd, GameData::team t, int d) const
{
  RatedMove	*ret;
  ChessBoard	board(gd);

  const std::list<Move *>	*successorStateList = NULL;
  successorStateList = board.getSuccessors(GameData::White);
  std::list<RatedMove *>	*ratedSuccessorStateList = NULL;
  ratedSuccessorStateList = new std::list<RatedMove *>(); // Alloc 5 (min-func)

  for (std::list<Move *>::const_iterator it = successorStateList->begin() ;
       it != successorStateList->end() ; ++it)
    {
      if (d == 0)
	ratedSuccessorStateList->push_back(new RatedMove(*it, eval((*it)->getGameData(), t))); // Alloc 4 (min-func)
      else
	ratedSuccessorStateList->push_back(max((*it)->getGameData(), t, d - 1));
    }
  ret = &(*min_element(boost::make_indirect_iterator(ratedSuccessorStateList->begin()), boost::make_indirect_iterator(ratedSuccessorStateList->end())));
  for (std::list<Move *>::const_iterator it = successorStateList->begin() ;
       it != successorStateList->end() ; ++it)
    {
      if (*it != ret)
	delete *it; // Un-alloc 8 (min-func)
    }
  for (std::list<RatedMove *>::iterator it = ratedSuccessorStateList->begin() ;
       it != ratedSuccessorStateList->end() ; ++it)
    {
      if (*it != ret)
	delete *it; // Un-alloc 4 (min-func) ! except one
    }
  delete ratedSuccessorStateList; // Un-alloc 5 (min-func)
  delete successorStateList; // Un-alloc 2 (min-func)
  return (ret);
}

RatedMove	*MinMax::max(GameData const &gd, GameData::team t, int d) const
{
  RatedMove	*ret;
  ChessBoard	board(gd);

  const std::list<Move *>	*successorStateList = NULL;
  successorStateList = board.getSuccessors(GameData::White);
  std::list<RatedMove *>	*ratedSuccessorStateList = NULL;
  ratedSuccessorStateList = new std::list<RatedMove *>(); // Alloc 5 (max-func)
  for (std::list<Move *>::const_iterator it = successorStateList->begin() ;
       it != successorStateList->end() ; ++it)
    {
      if (d == 0)
	ratedSuccessorStateList->push_back(new RatedMove(*it, eval((*it)->getGameData(), t))); // Alloc 4 (max-func)
      else
	{
	  ret = min((*it)->getGameData(), t, d - 1);
	  ratedSuccessorStateList->push_back(new RatedMove(*it, ret->getScore())); // Alloc 4 (max-func)
	  delete ret;
	}
    }
  ret = &(*max_element(boost::make_indirect_iterator(ratedSuccessorStateList->begin()), boost::make_indirect_iterator(ratedSuccessorStateList->end())));
  //  ret = *max_element(ratedSuccessorStateList->begin(), ratedSuccessorStateList->end());
  for (std::list<Move *>::const_iterator it = successorStateList->begin() ;
       it != successorStateList->end() ; ++it)
    {
      delete *it; // Un-alloc 8 (max-func)
    }
  for (std::list<RatedMove *>::iterator it = ratedSuccessorStateList->begin() ;
       it != ratedSuccessorStateList->end() ; ++it)
    {
      if (*it != ret)
	delete *it; // Un-alloc 4 (max-func) !exepct one
    }
  delete ratedSuccessorStateList; // Un-alloc 5 (max-func)
  delete successorStateList; // Un-alloc 2 (max-func)
  return (ret);
}

float		MinMax::eval(GameData const &gd, GameData::team t) const
{
  static int	counter(0);
  ChessBoard	c(gd);
  float		pieceVal[2] = {0, 0};

  const std::list<PieceInfo *>	*pieces;
  pieces = c.getPieces(t);
  for (std::list<PieceInfo *>::const_iterator it = pieces->begin() ; it != pieces->end() ; ++it)
    {
      pieceVal[t] += m_piecesVal[(*it)->getPiece()];
      delete *it; // Un-alloc 9
    }
  delete pieces; // Un-alloc 2
  pieces = c.getPieces(gd.getOtherTeam(t));
  for (std::list<PieceInfo *>::const_iterator it = pieces->begin() ; it != pieces->end() ; ++it)
    {
      pieceVal[gd.getOtherTeam(t)] += m_piecesVal[(*it)->getPiece()];
      delete *it; // Un-alloc 9
    }
  delete pieces; // Un-alloc 2

  // std::cout << gd << std::endl;
  // std::cout << (pieceVal[t] - pieceVal[gd.getOtherTeam(t)]) << " = " << pieceVal[t] << " - " <<  pieceVal[gd.getOtherTeam(t)] << std::endl;

  counter++;
  return (pieceVal[t] - pieceVal[gd.getOtherTeam(t)]);
}