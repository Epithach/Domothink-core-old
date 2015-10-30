#include <iostream>
#include <ostream>
#include "./include/exception.hpp"
#include "./include/utils.hpp"
#include "./include/server.hpp"

using boost::asio::ip::tcp;

int		main(int ac, char **av) {
  Server	server(my_atoi(av[1]));

  if (ac != 2) {
    std::cerr << "Usage : server [Port]" << std::endl;
    return (-1);
  } 
  try {
    server.run();
  } catch (const Exception &e)
    {   
      std::cerr << "Une erreur est survenue :" << std::endl
      << e.getMessage() << std::endl;
    }
  return 1;
}
