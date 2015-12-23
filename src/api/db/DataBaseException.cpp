include "DataBaseException.h"

DataBaseException::DataBaseException(const string & what) : std::runtime_error(what)
{}
