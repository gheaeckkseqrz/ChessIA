//
// King.hpp for ChessIA in /home/wilmot_p/PROG/C++/ChessIA
// 
// Made by WILMOT Pierre
// Login   <wilmot@epitech.net>
// 
// Started on  Tue Nov 27 00:29:52 2012 WILMOT Pierre
// Last update Tue Nov 27 00:35:26 2012 WILMOT Pierre
//

#ifndef __KING_HPP__
#define __KING_HPP__

#include	<iostream>
#include	"PieceInfo.hpp"

class King : public PieceInfo
{
 public:
  King(int x, int y, GameData::team t);
  ~King();

 private:

};

#endif
