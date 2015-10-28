#include "./include/exception.hpp"

Exception::Exception(std::string const& msg) throw():  msg(msg) {
}

Exception::~Exception() throw() {
}

const char*     Exception::what() const throw() {
  return (this->msg.c_str());
}
