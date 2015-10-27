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

void				test(std::string& str1, std::string& str2) 
{
  std::cout << str1 << std::endl;
  std::cout << str2 << std::endl;
  
  std::string chaine = str1 + str2;
  
  std::cout << chaine << std::endl;

  return ;
}

int		main()
{
  boost::array<int, 4> arr = {{1,2,3,4}};
  std::cout << "Hi" << arr[3] << std::endl;

  std::string str1 = "NIKE";
 std::string str2 = "TAMER";

 test((str1), (str2));

 server();
 
 return 1;
}
