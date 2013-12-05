//
// UCI.hpp for ChessIA in /home/wilmot_p/PROG/C++/ChessIA
// 
// Made by WILMOT Pierre
// Login   <wilmot@epitech.net>
// 
// Started on  Thu Jan  3 20:14:12 2013 WILMOT Pierre
// Last update Thu Dec  5 21:00:46 2013 WILMOT Pierre
//

#ifndef __UCI_HPP__
#define __UCI_HPP__

#include	<iostream>
#include	<queue>
#include	"Threadable.hpp"
#include	"Action.hpp"
#include	"Move.hpp"
#include	"Varcond.hpp"

class UCI : public Threadable
{
 public:
  UCI(std::string const & name, std::string const & author);
  ~UCI();


  Action		*getAction();

  /* -- Outgoing -- */
  bool			registerEngine() const;
  void			sendMove(Move const &a) const;
  void			readyOK();

protected:
  int			threadEntryPoint();

  /* -- Incoming -- */
  void			isReady();
  void			position(std::string const &s);
  void			go(std::string const &s);
  void			setDebug(std::string const & s);


  std::string		generateFenFromStarposMoves(std::string const &s) const;

 private:
  std::string		m_name;
  std::string		m_author;
  std::queue<Action *>	m_actionQueue;
  Mutex			m_actionQueueMutex;
  Varcond		m_varcond;
};

#endif
