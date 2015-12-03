#include <stdlib.h>
#include <iostream>

#include "mysql-connector-c++-1.1.6/driver/mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;


int mySqlMain(void)
{
	sql::Driver *driver;
	sql::Connection *con;
	sql::Statement *stmt;
	sql::ResultSet *res;
	/* Create a connection */
	driver = get_driver_instance();
	con = driver->connect("tcp://127.0.0.1:3306", "root", "root");
	/* Connect to the MySQL test database */
	con->setSchema("schema_test");


	stmt = con->createStatement();
	res = stmt->executeQuery("SELECT name AS _name FROM schema_test.table_test"); // replace with your statement

	while (res->next()) {
		cout << "\t... MySQL replies: ";
		// Access column data by alias or column name
		cout << res->getString("_name") << endl;
		cout << "\t... MySQL says it again: ";
		// Access column fata by numeric offset, 1 is the first column
		cout << res->getString(1) << endl;
	}

	delete res;
	delete stmt;
	delete con;
	
	return 0;
}
