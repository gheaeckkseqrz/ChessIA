//
// Varcond.cpp for ChessIA in /home/wilmot_p/PROG/C++/ChessIA
// 
// Made by WILMOT Pierre
// Login   <pierre.wilmot@gmail.com>
// 
// Started on  Wed Dec  4 22:03:01 2013 WILMOT Pierre
// Last update Wed Dec  4 22:42:03 2013 WILMOT Pierre
//

#include	<iostream>
#include	"Varcond.hpp"

Varcond::Varcond()
  :m_mutex(Mutex::Normal)
{
  pthread_cond_init (&m_varcond, NULL);
}

Varcond::~Varcond()
{
}

void				Varcond::wait()
{
  m_mutex.lock();
  pthread_cond_wait(&m_varcond, m_mutex.getCMutex());
  m_mutex.unlock();
}

void				Varcond::signal()
{
  m_mutex.lock();
  pthread_cond_signal(&m_varcond);
  m_mutex.unlock();
}

void				Varcond::broadcast()
{
  m_mutex.lock();
  pthread_cond_broadcast(&m_varcond);
  m_mutex.unlock();
}
