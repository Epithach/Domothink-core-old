#ifndef     IDATABASE_H_
# define    IDATABASE_H_

#include "DataBaseException.h"

class   IdataBase
{

public :

    virtual ~IdataBase() {};

    virtual IdataBase(const IdataBase &)    = delete;
    virtual IdataBase(IdataBase &&)         = delete;

    virtual IdataBase & operator=(IdataBase)    = delete;
    virtual IdataBase & operator=(IdataBase &&) = delete;

    virtual void    connect(const string && name, const string && password)    throw(DataBaseException) = 0;
    virtual void    disconnect()   throw(DataBaseException) = 0;

    virtual int     insertRow() throw(DataBaseException) = 0;
    virtual int     updateRow() throw(DataBaseException) = 0;
    virtual int     deleteRow() throw(DataBaseException) = 0;

    virtual void    createTable(const string & tableName)   throw(DataBaseException) = 0;
    virtual void    dropTable(const string & tableName)     throw(DataBaseException) = 0;

    virtual bool    hasUser(const string & name, const string & password)   throw(DataBaseException) = 0;

private :

    virtual string &&   fetch(const string && select)   throw(DataBaseException) = 0;

};  /* !IdataBase */

#endif  /* !IDATABASE_H_ */
