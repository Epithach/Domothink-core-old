#ifndef		EXCEPTION_HPP_
# define	EXCEPTION_HPP_

#include <stdexcept>
#include <string>

class Exception : public std::exception {
private:
  std::string   msg;

public:
  Exception(std::string const& msg) throw();
  virtual ~Exception() throw();

  virtual const char* getMessage() const throw();
};

#endif	/* !EXCEPTION_HPP_ */
