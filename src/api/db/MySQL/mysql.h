#ifndef		MYSQL_H_
# define	MYSQL_H_

#include <stdlib.h>
#include <iostream>

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

#include "../IdataBase.h"
#include "MySQLException.h"

using namespace std;

// To REVIEW when our database is set and fully usable :
// - Give parameters to "connect" and use them in the driver->connect function of MySQL
// - Give parameters to "insertElem" and "deleteElem" in order to add or remove the selected element of the table
// - "disconnect" is already operational, no need to change it


// Code to test this file (to put in the main)
/* MySQLdataBase base;

base.connect();
base.insertElem();
base.deleteElem();
base.disconnect();
*/

class MySQLdataBase : public IdataBase {

	sql::Driver				*driver;
	sql::Connection			*con;
	sql::Statement			*stmt;
	sql::PreparedStatement  *prep_stmt;

public:
			MySQLdataBase();
			~MySQLdataBase();
			MySQLdataBase(const MySQLdataBase &)    	= delete;
			MySQLdataBase(MySQLdataBase &&)         	= delete;
			MySQLdataBase & operator=(MySQLdataBase)    = delete;
			MySQLdataBase & operator=(MySQLdataBase &&) = delete;
			MySQLdataBase & swap(MySQLdataBase &)   	= delete;
			
    void    connect(const std::string & name, const std::string & password) throw(DataBaseException);
    void    disconnect() throw(DataBaseException);
	
    int     insertRow() throw(DataBaseException);
    int     updateRow() throw(DataBaseException);
    int     deleteRow() throw(DataBaseException);

	void    createTable(const std::string & tableName) throw(DataBaseException);
    void    dropTable(const std::string & tableName) throw(DataBaseException);

    bool    hasUser(const std::string & name, const std::string & password) throw(DataBaseException);

private:
	sql::ResultSet 	*fetch(const std::string & select)   throw(DataBaseException);
};

#endif	/* !MYSQL_H_ */