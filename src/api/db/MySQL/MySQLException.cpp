#include "MySQLException.h"

MySQLException::MySQLException(const std::string & what) noexcept : DataBaseException(what)
{
}
