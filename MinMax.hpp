//
// MinMax.hpp for ChessIA in /home/wilmot_p/PROG/C++/ChessIA
// 
// Made by WILMOT Pierre
// Login   <wilmot@epitech.net>
// 
// Started on  Wed Dec 26 01:53:02 2012 WILMOT Pierre
// Last update Wed Dec 26 02:32:24 2012 WILMOT Pierre
//

#ifndef __MINMAX_HPP__
#define __MINMAX_HPP__

#include	<iostream>
#include	"GameData.hpp"
#include	"Move.hpp"

class MinMax
{
 public:
  MinMax();
  ~MinMax();

  Move	const &	getBestMove(GameData const & current) const;

 private:

};

#endif
