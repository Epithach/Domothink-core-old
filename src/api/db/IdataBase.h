#ifndef     IDATABASE_H_
# define    IDATABASE_H_

#include "DataBaseException.h"

class   IdataBase
{

public :

    /* Rule of 5*/

    virtual ~IdataBase() {};

    virtual void    connect(const std::string && name, const std::string && password)    throw(DataBaseException) = 0;
    virtual void    disconnect()   throw(DataBaseException) = 0;

    virtual int     insertRow() throw(DataBaseException) = 0;
    virtual int     updateRow() throw(DataBaseException) = 0;
    virtual int     deleteRow() throw(DataBaseException) = 0;

    virtual void    createTable(const std::string & tableName)   throw(DataBaseException) = 0;
    virtual void    dropTable(const std::string & tableName)     throw(DataBaseException) = 0;

    virtual bool    hasUser(const std::string & name, const std::string & password)   throw(DataBaseException) = 0;

private :

    virtual std::string &&   fetch(const std::string && select)   throw(DataBaseException) = 0;

};  /* !IdataBase */

#endif  /* !IDATABASE_H_ */
