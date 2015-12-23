#ifndef     DATABASE_EXCEPTION_H_
# define    DATABASE_EXCEPTION_H_

#include <stdexcept>

class   DataBaseException : public std::runtime_error
{
    
public :

    explicit    DataBaseException(const std::string & what)  noexcept;

};  /* !DataBaseException */

#endif  /* !DATABASE_EXCEPTION_H_ */
