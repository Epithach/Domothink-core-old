#include "../include/postgre.hpp"

Postgre::Postgre(char *dbname, char *user, char *password, char *host, char *port) {

  setDbName(dbname);
  std::cout << "DbName : " <<this->DbName_ << std::endl;
  setUser(user);
  std::cout << "User : " <<this->User_ << std::endl;
  setPasswd(password);
  std::cout << "Passwd : " <<this->Passwd_ << std::endl;
  setHost(host);
  std::cout << "Host : " <<this->Host_ << std::endl;
  setPort(atoi(port));
  std::cout << "Port : " <<this->Port_ << std::endl;
    
  std::cout << "Constructor : Ok" << std::endl << std::endl;
}


Postgre::~Postgre() {
  std::cout << std::endl << "Destructor : Ok" << std::endl;
}

void		Postgre::run() {

  std::cout << "POSTGRE GO >>>" << std::endl;

  /**
   * Convert our DbName_ to be readable by PQconnectdb
   */
  setConninfo();
  std::cout << "Conninfo : " << this->conninfo << std::endl;

  /**
   * Connection to the database
   */
  this->conn = PQconnectdb((getConninfo()).c_str());

  /**
   * Checking if the connection is Ok
   */
  if (PQstatus(conn) != CONNECTION_OK) {
    fprintf(stderr, "Connection to database failed: %s",
	    PQerrorMessage(conn));
    throw ;
  } else
    std::cout << "Connection to database : Ok" << std::endl;
  
  return ;
}

void		Postgre::setDbName(char *db) {
  this->DbName_ = db;
  return ;
}

std::string	Postgre::getDbName() const  {
  return this->DbName_;
}

void		Postgre::setUser(char *user) {
  this->User_ = user;
  return ;
}

std::string	Postgre::getUser() const {
  return this->User_;
}

void		Postgre::setPasswd(char *pass) {
  this->Passwd_ = pass;
  return ;
}

std::string	Postgre::getPasswd() const {
  return this->Passwd_;
}

void		Postgre::setHost(char *host) {
  this->Host_ = host;
  return ;
}

std::string	Postgre::getHost() const {
  return this->Host_;
}

void		Postgre::setPort(int port) {
  this->Port_ = port;
}

int		Postgre::getPort() const {
  return this->Port_;
}

void		Postgre::setConninfo() {
  std::string port;
  std::ostringstream convert;
  
  convert << this->Port_;
  port = convert.str();
  this->conninfo = "dbname=" + this->DbName_ + " user=" + this->User_ + " password=" + this->Passwd_;// + " host=" + this->Host_ + " port=" + port;
  
  return ;
  
}

std::string	Postgre::getConninfo() const {
  return this->conninfo;
}
