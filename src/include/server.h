#ifndef			SERVER_HPP_
# define		SERVER_HPP_

#include	<boost/asio.hpp>
#include	<boost/array.hpp>

using		boost::asio::ip::tcp;

class			Server {
private :
  int			Port_;
  int			Fd_;
  std::string		Ip_;
public :
  Server(int);
  ~Server();
  Server(const Server &);
  Server		&operator=(const Server &);

  /* Set & Get */
  void			setPort(int);
  int			getPort() const;
  void			setIp(std::string);
  std::string		getIp() const;
  void			setFd(int);
  int			getFd() const;

  /* Functions */
  void			run();
};

#endif			/* SERVER_HPP_ */
