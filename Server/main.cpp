#include <iostream>
#include <ostream>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include "./include/exception.hpp"
#include "./include/utils.hpp"

using boost::asio::ip::tcp;

void				server(int port)
{
  boost::asio::io_service	ios;
  tcp::acceptor			acceptor(ios, tcp::endpoint(tcp::v4(), port));
  std::string			msg ("Bienvenue a toi fils!");

  while (1) {
    tcp::socket			socket(ios);
    acceptor.accept(socket);
    std::cout << "IZI" << std::endl; 
    socket.send(boost::asio::buffer(msg));
  }
  return ;
}

int		main(int ac, char **av)
{
  int		port;
  if (ac != 2) {
    std::cout << "Usage : server [Port]" << std::endl;
    return (-1);
  }
  try {
    port = my_atoi(av[1]);
    server(port);
  } catch (const Exception &e)
    {   
      std::cout << "Une erreur est survenue :" << std::endl;
      std::cout << e.getMessage() << std::endl;
    }
  return 1;
}
