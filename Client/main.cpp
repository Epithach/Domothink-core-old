#include <iostream>
#include <ostream>
#include <boost/asio.hpp>
#include <boost/array.hpp>

int					client()
{
  boost::asio::io_service		ios;
  boost::asio::ip::tcp::endpoint	endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 7171);
  boost::asio::ip::tcp::socket		socket(ios);
  boost::array<char, 128>		buf;
  boost::system::error_code		error;
  int					len;
 
  socket.connect(endpoint);
  while (1) {
    socket.read_some(boost::asio::buffer(buf), error);
    
    if (error == boost::asio::error::eof)  {
      std::cout << "Deco" << std::endl;
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
    std::cout << "Usage : server [IP Adress] [Port]" << std::endl;
    return (-1);
  }

  client();
  return 1;
}
