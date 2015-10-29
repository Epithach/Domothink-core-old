#include <iostream>
#include <ostream>
#include "./include/exception.hpp"
#include "./include/utils.hpp"
#include "./include/client.hpp"

int		main(int ac, char **av)
{
  Client	client(std::string(av[1]), my_atoi(av[2]));	

  if (ac != 3) {
    std::cerr << "Usage : client [IP Adress] [Port]" << std::endl;
    return (-1);
  } 
  try {
    client.run();
  } catch (const Exception &e)
    {
      std::cerr << "Une erreur est survenue :" << std::endl;
      std::cerr << e.getMessage() << std::endl;
    }
  return 1;
}
