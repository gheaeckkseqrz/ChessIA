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

int	main(int ac, char **av)
{
  (void) ac;
  (void) av;

  ChessBoard	board;

  const std::list<PieceInfo *>	*l;

  std::cout << board << std::endl;
  l = board.getPieces(GameData::White);

  for (std::list<PieceInfo *>::const_iterator it = l->begin() ; it != l->end() ; ++it)
    {
      (*it)->getSuccessors(board);
    }
}
