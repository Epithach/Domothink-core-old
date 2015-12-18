#ifndef		POSTGRE_HPP_
# define	POSTGRE_HPP_

#include <iostream>
#include <ostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <libpq-fe.h>

class		Postgre {
private:
  char		*DbName_;
  char		*User_;
  char		*Passwd_;
  char		*Host_;
  int		Port_;

  PGconn	*conn;
  char		*conninfo;

public:
  Postgre(char *, char *, char *, char *, char *);
  ~Postgre();

  void		run();

  bool		setConninfo();
  char		*getConninfo() const;
  bool		setDbName(char *);
  char		*getDbName() const;
  bool		setUser(char *);
  char		*getUser() const;
  bool		setPasswd(char *);
  char		*getPasswd() const;
  bool		setHost(char *);
  char		*getHost() const;
  void		setPort(int);
  int		getPort() const;
};

#endif		/* !POSTGRE_HPP_ */