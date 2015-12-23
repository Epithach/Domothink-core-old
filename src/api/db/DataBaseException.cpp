#include "DataBaseException.h"

DataBaseException::DataBaseException(const std::string & what) noexcept : std::runtime_error(what)
{}
