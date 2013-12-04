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
#include	"MinMax.hpp"
#include	"OptionsParser.hpp"
#include	"UCI.hpp"
#include	"Action.hpp"
#include	"LogManager.hpp"

int	main(int ac, char **av)
{
  try
    {
      OptionsParser	op(ac, av);
      ChessBoard	board;
      MinMax		mm(op.getDepth());
      UCI		uci("ChessIA", "Pierre WILMOT");
      Action		*action;

      while (!uci.mustQuit())
	{
	  action = uci.getAction();
	  if (action)
	    {
	      if (action->getType() == Action::Position)
		board.setFromFen(action->getFen());
	      else if (action->getType() == Action::Go)
		{
		  const Move m = mm.getBestMove(board, GameData::White);
		  uci.sendMove(m);
		}
	    }
	}
    }
  catch(std::exception& e)
    {
      std::cerr << "Unhandled Exception reached the top of main: "
		<< e.what() << ", application will now exit" << std::endl;
      return (2);
    }
}
