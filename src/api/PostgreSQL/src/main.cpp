#include <iostream>
#include <ostream>
#include <string>
#include "../include/exception.hpp"
#include "../include/postgre.hpp"

int		main(int ac, char **av)
{
  std::cout << "START" << std::endl << std::endl;

  if (ac != 6) {
    std::cerr << "Usage : postgre [DbName] [User] [Password] [IP Adress] [Port]" << std::endl;
    return (-1);
  } try {
    Postgre psql(av[1], av[2], av[3], av[4], av[5]); 
    psql.run();
  } catch (const Exception &e) {
    std::cerr << "Une erreur est survenue :" << std::endl;
    std::cerr << e.getMessage() << std::endl;
  }
  return 1;
}
