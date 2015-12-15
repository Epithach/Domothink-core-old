#include <stdlib.h>
#include <iostream>

#include "mysql-connector-c++-1.1.6/driver/mysql_connection.h"

#include "mySql.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;


int main(void)
{
  MySQLdataBase base;

  base.connect();
  base.insertElem();
  base.disconnect();
	return 0;
}
