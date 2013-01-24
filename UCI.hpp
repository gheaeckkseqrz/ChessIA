//
// UCI.hpp for ChessIA in /home/wilmot_p/PROG/C++/ChessIA
// 
// Made by WILMOT Pierre
// Login   <wilmot@epitech.net>
// 
// Started on  Thu Jan  3 20:14:12 2013 WILMOT Pierre
// Last update Wed Jan 23 23:01:40 2013 WILMOT Pierre
//

#ifndef __UCI_HPP__
#define __UCI_HPP__

#include	<iostream>
#include	<queue>
#include	"Threadable.hpp"
#include	"Action.hpp"
#include	"Move.hpp"

class UCI : public Threadable
{
 public:
  UCI(std::string const & name, std::string const & author);
  ~UCI();

  bool			registerEngine() const;
  int			threadEntryPoint();
  void			setDebug(std::string const & s);
  void			setDebug(bool b);
  void			isReady();
  void			position(std::string const &s);
  Action		*getAction();
  void			sendMove(Move const &a) const;
  void			go(std::string const &s);
  std::string		generateFenFromStarposMoves(std::string const &s) const;

 private:
  std::string		m_name;
  std::string		m_author;
  std::queue<Action *>	m_actionQueue;
  Mutex			m_actionQueueMutex;
  // TODO : Encapsuler la varcond
  pthread_cond_t	m_varcond;
};

#endif
