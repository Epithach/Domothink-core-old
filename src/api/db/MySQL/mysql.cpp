#include <stdlib.h>
#include <iostream>

#include "mysql-connector-c++-1.1.6/driver/mysql_connection.h"
#include "MySQLException.h"
#include "mysql.h"

#include <exception>

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;

MySQLdataBase::MySQLdataBase()
{
	this->driver = nullptr;
	this->con = nullptr;
	this->stmt = nullptr;
	this->prep_stmt = nullptr;
}

MySQLdataBase::~MySQLdataBase()
{
	this->driver = nullptr;
	this->con = nullptr;
	this->stmt = nullptr;
	this->prep_stmt = nullptr;
}

void MySQLdataBase::connect(const std::string & name, const std::string & password)
{
		/* Create a connection */
		try {
			this->driver = get_driver_instance();
			this->con = driver->connect("tcp://127.0.0.1:3306", "root", "root");
		} catch (sql::SQLException &e) {
			throw MySQLException("MySQL Exception (On Connection) : " + std::string(e.what()));
		}	
		/* Connect to the MySQL test database */
		this->con->setSchema("ta");
}

void MySQLdataBase::disconnect()
{
	this->con->close();
	delete con;
	this->driver->threadEnd();
}

int MySQLdataBase::insertRow()
{
	if (this->con == nullptr)
	{
		throw MySQLException("MySQL Exception (On Row Insertion) : Connection is not set");
	}
	this->prep_stmt = con->prepareStatement("INSERT INTO table_test(id, name, password) VALUES (?, ?, ?)");

	this->prep_stmt->setInt(1, 4);
	this->prep_stmt->setString(2, "box4");
	this->prep_stmt->setString(3, "box4pass");
	this->prep_stmt->execute();

	delete this->prep_stmt;
	return 0; // devra return le nombre de row add
}

int MySQLdataBase::updateRow()
{
	if (this->con == nullptr)
	{
		throw MySQLException("MySQL Exception (On Row Update) : Connection is not set");
	}
	return 0;
}

int MySQLdataBase::deleteRow()
{
	if (this->con == nullptr)
	{
		throw MySQLException("MySQL Exception (On Row Deletion) : Connection is not set");
	}
	this->prep_stmt = con->prepareStatement("DELETE FROM table_test WHERE id = ?");

	this->prep_stmt->setInt(1, 4);
	this->prep_stmt->execute();

	delete this->prep_stmt;
	return 0; // devra retourner le nombre de row delete
}

sql::ResultSet 	*MySQLdataBase::fetch(const string & request)
{
	sql::ResultSet 	*res;
	std::string resultString("");
	
	if (this->con == nullptr) {
		throw MySQLException("MySQL Exception (On Fetching Data) : Connection is not set");
	}
	this->stmt = con->createStatement();
	try {	
		res = stmt->executeQuery(request.c_str()); // replace with your statement
    } catch (std::exception& e) {
		throw MySQLException("MySQL Exception (On Data Fetching) : " + std::string(e.what()));
    }
	/*while (res->next()) {
		// Access column data by alias or column name
	}*/
	delete stmt;
	stmt = nullptr;
	return res;
}

void    MySQLdataBase::createTable(const std::string & tableName) throw(DataBaseException)
{
	std::string		request("CREATE TABLE `" + tableName + "` (`id` INT NOT NULL, PRIMARY KEY (`id`))");
	
	this->prep_stmt = con->prepareStatement(request.c_str());
	try {
	this->prep_stmt->execute();
    } catch (std::exception& e) {
		throw MySQLException("MySQL Exception (On Creating Table) : " + std::string(e.what()));
    }
	delete this->prep_stmt;
}
	
void    MySQLdataBase::dropTable(const std::string & tableName) throw(DataBaseException)
{
	std::string		request("DROP TABLE `" + tableName + "`");

	this->prep_stmt = con->prepareStatement(request.c_str());
	try {
	this->prep_stmt->execute();
    } catch (std::exception& e) {
		throw MySQLException("MySQL Exception (On Deleting Table) : " + std::string(e.what()));
    }
	delete this->prep_stmt;
}
	
bool MySQLdataBase::hasUser(const string & name, const string & password)
{
	std::string 	request("SELECT * FROM user WHERE user.name = '" + name + "' AND user.password = '" + password + "'");
	sql::ResultSet 	*res;
	bool 			userExist(false);

	res = fetch(request);
	if (res->rowsCount() == 1)
	{
		userExist = true;
	}
	return userExist;
}