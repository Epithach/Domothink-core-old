#include <iostream>
#include <ostream>

int		main(int ac, char **av)
{
  if (ac != 6) {
    std::cerr << "Usage : postgre [DbName] [User] [Password] [IP Adress] [Port]" << std::endl;
    return (-1);
  }  try {
    client.run();
  } catch (const Exception &e)
    {
      std::cerr << "Une erreur est survenue :" << std::endl;
      std::cerr << e.getMessage() << std::endl;
    }
  return 1;
}
