#include "exception.h"

Exception::Exception(std::string const& msg) throw():  msg(msg) {
}

Exception::~Exception() throw() {
}

const char*     Exception::getMessage() const throw() {
  return (this->msg.c_str());
}
