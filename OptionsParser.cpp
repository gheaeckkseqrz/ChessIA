//
// OptionsParser.cpp for ChessIA in /home/wilmot_p/PROG/C++/ChessIA
// 
// Made by WILMOT Pierre
// Login   <wilmot@epitech.net>
// 
// Started on  Sun Dec 30 21:31:51 2012 WILMOT Pierre
// Last update Sun Dec 30 22:21:00 2012 WILMOT Pierre
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
      std::cout << "Depth was set to " << vm["depth"].as<int>() << std::endl;
      m_depth = vm["depth"].as<int>();
    }

  std::cout << "Ooption Done : Depth : " << m_depth << std::endl;

}

OptionsParser::~OptionsParser()
{
}

int			OptionsParser::getDepth() const
{
  return (m_depth);
}
