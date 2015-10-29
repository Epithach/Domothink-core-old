#include <iostream>
#include <ostream>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include "./include/exception.hpp"
#include "./include/utils.hpp"

int					client(std::string ip, int port)
{
  boost::asio::io_service		ios;
  boost::asio::ip::tcp::endpoint	endpoint(boost::asio::ip::address::from_string(ip), port);
  boost::asio::ip::tcp::socket		socket(ios);
  boost::array<char, 128>		buf;
  boost::system::error_code		error;
  int					len;
 
  socket.connect(endpoint);
  while (1) {
    socket.read_some(boost::asio::buffer(buf), error);
    
    if (error == boost::asio::error::eof)  {
      std::cout << "Déconnexion" << std::endl;
      break;
    }
    
    std::cout.write(buf.data(), len);
  }
  return 1;
}

int		main(int ac, char **av)
{
  std::string	ip;
  int		port;	

  if (ac != 3) {
    std::cerr << "Usage : client [IP Adress] [Port]" << std::endl;
    return (-1);
  } 
  try {
    ip = std::string(av[1]);
    port = my_atoi(av[2]);
    client(ip, port);
  } catch (const Exception &e)
    {
      std::cerr << "Une erreur est survenue :" << std::endl;
      std::cerr << e.getMessage() << std::endl;
    }
  return 1;
}
