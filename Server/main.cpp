#include <iostream>
#include <ostream>
#include <boost/asio.hpp>
#include <boost/array.hpp>

using boost::asio::ip::tcp;

void				server()
{
  boost::asio::io_service	ios;
  tcp::acceptor			acceptor(ios, tcp::endpoint(tcp::v4(), 7171));
  std::string			msg ("Bienvenue a toi fils!");
      

  while (1) {
    tcp::socket			socket(ios);
    acceptor.accept(socket);
    std::cout << " IZI " << std::endl; 
    socket.send(boost::asio::buffer(msg));
  }
  return ;
}

int		main(int ac, char **av)
{
  if (ac != 3) {
    std::cout << "Usage : server [Port]" << std::endl;
    return (-1);
  }

  

 server();
 return 1;
}
