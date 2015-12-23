#include <iostream>

#include "exception.h"
#include "server.h"
#include "utils.h"
#include "mysql.h"

// Include used to test the mySQL connectors -> can be removed if needed
//#include "../test/mysql/mySql.h"

using boost::asio::ip::tcp;

int		main(int ac, char *av[]) {


  if (ac != 2) {
    std::cerr << "Usage : server [Port]" << std::endl;
    return (-1);
  }
	// Code used to test the mySQL connectors -> can be removed if needed
	/* MySQLdataBase base;

	base.connect();
	base.insertElem();
	base.deleteElem();
	base.disconnect();
*/
  return 0;
}

/*
Server	server(my_atoi(av[1]));
try {
  server.run();
} catch (const Exception &e)
  {
    std::cerr << "Une erreur est survenue :" << std::endl
    << e.getMessage() << std::endl;
  }



*/
