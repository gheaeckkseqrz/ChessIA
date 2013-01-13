//
// OptionsParser.cpp for ChessIA in /home/wilmot_p/PROG/C++/ChessIA
// 
// Made by WILMOT Pierre
// Login   <wilmot@epitech.net>
// 
// Started on  Sun Dec 30 21:31:51 2012 WILMOT Pierre
// Last update Thu Jan  3 22:43:23 2013 WILMOT Pierre
//

#include	<iostream>
#include	"OptionsParser.hpp"

OptionsParser::OptionsParser(int ac, char **av)
{
  po::options_description	desc("Options");
  po::variables_map		vm;

  desc.add_options()
    ("help,h", "Print help messages")
    ("depth,d", po::value<int>(&m_depth)->default_value(2), "MinMax depth level");

  po::store(po::parse_command_line(ac, av, desc), vm); // Can throw
  if (vm.count("help"))
    {
      std::cout << "Chess IA" << std::endl
		<< desc << std::endl;
      // Have to throw
    }
  if (vm.count("depth"))
    {
      m_depth = vm["depth"].as<int>();
    }
}

OptionsParser::~OptionsParser()
{
}

int			OptionsParser::getDepth() const
{
  return (m_depth);
}
