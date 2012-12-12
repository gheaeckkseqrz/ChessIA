//
// Bishop.hpp for ChessIA in /home/wilmot_p/PROG/C++/ChessIA
// 
// Made by WILMOT Pierre
// Login   <wilmot@epitech.net>
// 
// Started on  Tue Nov 27 00:29:00 2012 WILMOT Pierre
// Last update Tue Nov 27 00:35:34 2012 WILMOT Pierre
//

#ifndef __BISHOP_HPP__
#define __BISHOP_HPP__

#include	<iostream>
#include	"PieceInfo.hpp"

class Bishop : public PieceInfo
{
 public:
  Bishop(int x, int y, GameData::team t);
  ~Bishop();

 private:

};

#endif
