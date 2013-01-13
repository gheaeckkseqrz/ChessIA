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

int	main(int ac, char **av)
{
  try
    {
      UCI		uci("ChessIA", "Pierre WILMOT");
      OptionsParser	op(ac, av);
      ChessBoard	board;
      MinMax		mm(op.getDepth());

      Move	a = mm.getBestMove(board, GameData::White);

      while (!uci.mustQuit());

      // std::cout << a.getGameData();
      // std::cout << a.getSX() << "/" << a.getSY() << " => " << a.getDX() << "/" << a.getDY() << std::endl;
    }
  catch(std::exception& e)
    {
      std::cerr << "Unhandled Exception reached the top of main: "
		<< e.what() << ", application will now exit" << std::endl;
      return (2);
    }
}
