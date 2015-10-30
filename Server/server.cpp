#include "./include/server.hpp"

Server::Server(int port) {
  this->Port_ = port;
}

Server::~Server() {
}

Server::Server(const Server &other) {
  if (this != &other) {
    this->setPort(other.getPort());
    this->setFd(other.getFd());
    this->setIp(other.getIp());
  }
}

Server		&Server::operator=(const Server &other) {
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

void		Server::setPort(int port) {
  this->Port_ = port;
  return ;
}

int		Server::getPort() const {
  return (this->Port_);
}

void		Server::setIp(std::string ip) {
  this->Ip_ = ip;
  return ;
}

std::string	Server::getIp() const {
  return (this->Ip_);
}

void		Server::setFd(int fd) {
  this->Fd_ = fd;
  return ;
}

int		Server::getFd() const {
  return (this->Fd_);
}

/*
 * Functions
 */

void				Server::run() {
  boost::asio::io_service       ios;
  tcp::acceptor			acceptor(ios, tcp::endpoint(tcp::v4(), this->Port_));
  std::string			msg ("Bienvenue a toi !");

  while (1) {
    tcp::socket	socket(ios);
    acceptor.accept(socket);
    std::cout << "Client reçus" << std::endl;
    socket.send(boost::asio::buffer(msg));
  }
  return ;
}
