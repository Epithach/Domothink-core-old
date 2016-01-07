#ifndef     MYSQL_EXCEPTION_H_
# define    MYSQL_EXCEPTION_H_

#include "DataBaseException.h"

class   MySQLException : public DataBaseException
{
    
public :

		MySQLException(const std::string & what) noexcept;

};  /* !MySQLException */

#endif  /* !MYSQL_EXCEPTION_H_ */
