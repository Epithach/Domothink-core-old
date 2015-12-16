#include <iostream>
#include <ostream>
#include "./include/client.hpp"

Client::Client(std::string ip, int port) {
  this->Ip_ = ip;
  this->Port_ = port;
}

Client::~Client() {

}

Client::Client(const Client &other) {
  if (this != &other) {
    this->setPort(other.getPort());
    this->setFd(other.getFd());
    this->setIp(other.getIp());
  }
}

Client					&Client::operator=(const Client &other) {
  if (this != &other) {
    this->setPort(other.getPort());
    this->setFd(other.getFd());
    this->setIp(other.getIp());
  }
  return (*this);
}

/*
 * Set & Get
 */

/*void					Client::setIos(boost::asio::io_service ios) {
  this->Ios_ = ios;
  return ;
  }*/

/*boost::asio::io_service			Client::getIos() const {
  return (this->Ios_);
  }*/

void					Client::setPort(int port) {
  this->Port_ = port;
  return ;
}

int					Client::getPort() const {
  return (this->Port_);
}

void					Client::setIp(std::string ip) {
  this->Ip_ = ip;
  return ;
}

std::string				Client::getIp() const {
  return (this->Ip_);
}

void					Client::setFd(int fd) {
  this->Fd_ = fd;
  return ;
}

int					Client::getFd() const {
  return (this->Fd_);
}

/*
 * Functions
 */

int					Client::run() {
  boost::asio::io_service		ios;
  boost::asio::ip::tcp::endpoint	endpoint(boost::asio::ip::address::from_string(this->Ip_),this->Port_);
  boost::asio::ip::tcp::socket		socket(/* Ios_ */ios);
  boost::array<char, 128>		buf;
  boost::system::error_code		error;
  int					len;

  socket.connect(endpoint);
  while (1) {
    socket.read_some(boost::asio::buffer(buf), error);

    if (error == boost::asio::error::eof)  {
      std::cerr << "Déconnexion" << std::endl;
      break ;
    }

    std::cout.write(buf.data(), len);
  }
  return 1;
}
