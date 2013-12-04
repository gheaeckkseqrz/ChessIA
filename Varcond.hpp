//
// Varcond.hpp for Chess IA in /home/wilmot_p/PROG/C++/ChessIA
// 
// Made by WILMOT Pierre
// Login   <pierre.wilmot@gmail.com>
// 
// Started on  Wed Dec  4 22:00:50 2013 WILMOT Pierre
// Last update Wed Dec  4 22:12:21 2013 WILMOT Pierre
//

#ifndef __VARCOND_HPP__
#define __VARCOND_HPP__

#include	<iostream>
#include	"Mutex.hpp"

class Varcond
{
 public:
  Varcond();
  ~Varcond();

  void			wait();
  void			signal();
  void			broadcast();

 private:
  Mutex			m_mutex;
  pthread_cond_t	m_varcond;
};

#endif
