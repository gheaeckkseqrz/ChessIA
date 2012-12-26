//
// main.cpp for Chess IA in /home/wilmot_p/PROG/C++/[2012-11-26] - Chess IA
// 
// Made by WILMOT Pierre
// Login   <wilmot@epitech.net>
// 
// Started on  Mon Nov 26 20:42:26 2012 WILMOT Pierre

//

#include	<iostream>
#include	"ChessBoard.hpp"
#include	"Move.hpp"

int	main(int ac, char **av)
{
  (void) ac;
  (void) av;

  ChessBoard	board;

  const std::list<PieceInfo *>	*l;

  std::cout << board << std::endl;
  l = board.getPieces(GameData::White);

  std::list<Move *>	*successorStateList = NULL;
  std::list<Move *>	*successorStateListTmp = NULL;
  successorStateList = new std::list<Move *>();

  for (std::list<PieceInfo *>::const_iterator it = l->begin() ; it != l->end() ; ++it)
    {
      successorStateListTmp = (*it)->getSuccessors(board);
      successorStateList->splice(successorStateList->end(), *successorStateListTmp);
      delete successorStateListTmp;
    }
  if (successorStateList != NULL)
    {
      for (std::list<Move *>::iterator it2 = successorStateList->begin() ;
	   it2 != successorStateList->end() ; ++it2)
	{
	  std::cout << **it2 << std::endl;
	}
    }
  std::cout << successorStateList->size() << " possible moves" << std::endl;
}
