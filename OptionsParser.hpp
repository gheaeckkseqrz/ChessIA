//
// OptionsParser.hpp for ChessIA in /home/wilmot_p/PROG/C++/ChessIA
// 
// Made by WILMOT Pierre
// Login   <wilmot@epitech.net>
// 
// Started on  Sun Dec 30 21:32:01 2012 WILMOT Pierre
// Last update Sun Jan 13 19:40:51 2013 WILMOT Pierre
//

#ifndef __OPTIONSPARSER_HPP__
#define __OPTIONSPARSER_HPP__

#include	<iostream>
#include	"boost/program_options.hpp"

namespace po = boost::program_options;

class OptionsParser
{
 public:
  OptionsParser(int ac, char **av);
  ~OptionsParser();

  int		getDepth() const;

 private:
  int		m_depth;
  int		m_debug;
};

#endif
