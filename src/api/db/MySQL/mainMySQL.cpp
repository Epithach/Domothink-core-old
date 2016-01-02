#include <stdlib.h>
#include <iostream>

#include "mysql-connector-c++-1.1.6/driver/mysql_connection.h"
#include "mysql.h"

int test_main(void)
{
  MySQLdataBase base;

  base.connect("root", "root");
  base.insertRow();
  base.hasUser("guenno_v", "1234");
  base.disconnect();
	return 0;
}