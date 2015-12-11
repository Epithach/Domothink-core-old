#ifndef		POSTGRE_HPP_
# define	POSTGRE_HPP_

#include <iostream>
#include <ostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "/usr/include/postgresql/libpq-fe.h"

class		Postgre {
private:
  char		*DbName_;
  char		*User_;
  char		*Passwd_;
  char		*Ip_;
  int		Port_;
public:
  Postgre(char *, char *, char *, char *, char *);
  ~Postgre();

  void		run();
  bool		setDbName(char *);
  char		*getDbName() const;
  bool		setUser(char *);
  char		*getUser() const;
  bool		setPasswd(char *);
  char		*getPasswd() const;
  bool		setIp(char *);
  char		*getIp() const;
  void		setPort(int);
  int		getPort() const;
};

#endif		/* !POSTGRE_HPP_ */
