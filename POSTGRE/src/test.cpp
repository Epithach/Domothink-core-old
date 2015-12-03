#include <iostream>
#include <pqxx/pqxx> 

using namespace pqxx;

int main(int argc, char* argv[])
{


  /**
   * Connection à la DB
   */
  try {
    connection C("dbname=test user=antoine password=8pYK*kK7 \
      hostaddr=127.0.0.1 port=5432");
    if (C.is_open()) {
      std::cout << "Opened database successfully: " << C.dbname() << std::endl;
    } else {
      std::cout << "Can't open database" << std::endl;
      return -1;
    }
    
    /**
     * Création d'une instance SQL
     */
    std::string sql = "CREATE TABLE COMPANY("	 \
      "ID INT PRIMARY KEY     NOT NULL," \
      "NAME           TEXT    NOT NULL," \
      "AGE            INT     NOT NULL," \
      "ADDRESS        CHAR(50),"	 \
      "SALARY         REAL );";
    
    /**
     * Cration d'object pour la "transaction"
     */
    work W(C);

    /**
     * Execution des Action SQL
     */
    W.exec(sql);
    W.commit();
    std::cout << "Table created successfully" << std::endl;

    // Déconnection
    C.disconnect ();


  } catch (const std::exception &e){
    std::cerr << e.what() << std::endl;
    return -1;
  }
  return 1;
}
