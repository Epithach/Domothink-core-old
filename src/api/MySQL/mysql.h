#ifndef		MYSQL_H_
# define	MYSQL_H_

#include <stdlib.h>
#include <iostream>

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

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

class MySQLdataBase {

	sql::Driver				*driver;
	sql::Connection			*con = NULL;
	sql::Statement		*stmt;
	sql::PreparedStatement  *prep_stmt;
	sql::ResultSet		*res;

public:

	int connect(void)
	{
		/* Create a connection */
		this->driver = get_driver_instance();
		this->con = driver->connect("tcp://127.0.0.1:3306", "root", "root");
		
		/* Connect to the MySQL test database */
		this->con->setSchema("ta");

		/* Code in order to test your connection with the database */
		/*stmt = con->createStatement();
		res = stmt->executeQuery("SELECT name AS _name FROM user"); // replace with your statement

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
		delete con;*/

		return 0;
	}

	int disconnect(void)
	{
		this->con->close();
		delete con;
		this->driver->threadEnd();
		return 0;
	}

	int insertElem(void)
	{
		if (this->con != NULL)
		{
			/* Old way of doing things */
			/*stmt = con->createStatement();
			res = stmt->executeQuery("SELECT name AS _name FROM schema_test.table_test");*/

			this->prep_stmt = con->prepareStatement("INSERT INTO table_test(id, name, password) VALUES (?, ?, ?)");

			this->prep_stmt->setInt(1, 4);
			this->prep_stmt->setString(2, "box4");
			this->prep_stmt->setString(3, "box4pass");
			this->prep_stmt->execute();
			
			delete this->prep_stmt;
		}
		return 0;
	}

	int deleteElem(void)
	{
		if (this->con != NULL)
		{
			this->prep_stmt = con->prepareStatement("DELETE FROM table_test WHERE id = ?");

			this->prep_stmt->setInt(1, 4);
			this->prep_stmt->execute();

			delete this->prep_stmt;
		}
		return 0;
	}

	const string &&	fetch(const string && request)
	{
		std::string resultString("");

		if (this->con == nullptr) {
			return std::move(resultString);
		}

		this->stmt = con->createStatement();
		res = stmt->executeQuery(request); // replace with your statement

		while (res->next()) {
			// Access column data by alias or column name
			resultString = res->getString(2);
		}

		delete res;
		res = nullptr;
		delete stmt;
		stmt = nullptr;
		return std::move(resultString);
	}


	bool hasUser(const string & name, const string & password)
	{
		std::string 	request("SELECT * FROM user WHERE user.name = '" + name + "' AND user.password = '" + password + "'");
		std::string 	resultString("");
		bool 		userExist(false);

		resultString = fetch(std::move(request));
		if (resultString == name)
		{
			userExist = true;
		}
		return userExist;
	}

};

#endif	/* !MYSQL_H_ */

