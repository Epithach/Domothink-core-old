#ifndef		POSTGRE_HPP_
# define	POSTGRE_HPP_

#include <iostream>
#include <ostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>

class		Postgre {
private:
  std::string	DbName_;
  std::string	User_;
  std::string	Passwd_;
  std::string	Host_;
  int		Port_;

  PGconn	*conn;
  std::string	conninfo;

public:
  Postgre(char *, char *, char *, char *, char *);
  ~Postgre();

  void		run();

  void		setConninfo();
  std::string	getConninfo() const;
  void		setDbName(char *);
  std::string	getDbName() const;
  void		setUser(char *);
  std::string	getUser() const;
  void		setPasswd(char *);
  std::string	getPasswd() const;
  void		setHost(char *);
  std::string	getHost() const;
  void		setPort(int);
  int		getPort() const;
};

#endif		/* !POSTGRE_HPP_ */
