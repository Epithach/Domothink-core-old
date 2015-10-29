#ifndef					CLIENT_HPP_
# define				CLIENT_HPP_

#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <iostream>

class					Client {
private:
  boost::asio::io_service               Ios_;
  //boost::asio::ip::tcp::endpoint        endpoint(boost::asio::ip::address::from_string(ip), port);
  //boost::asio::ip::tcp::socket          socket(ios);
  int					Port_;
  int					Fd_;
  std::string				Ip_;
public:
  Client(std::string, int);
  ~Client();
  Client(const Client &);
  Client				&operator=(const Client &);
  
  /* SET & GET */
  //void					setIos(boost::asio::io_service);
  //boost::asio::io_service		getIos() const;
  void					setPort(int);
  int					getPort() const;
  void					setIp(std::string);
  std::string				getIp() const;
  void					setFd(int);
  int					getFd() const;

  /* Function */
  int					run();
};

#endif					/* !CLIENT_HPP_ */
