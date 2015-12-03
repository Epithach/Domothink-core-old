
#include "utils.h"

int			my_atoi(const std::string& String)
{
  int			i;
  std::stringstream	ss(String);

  ss >> i;
  return (i);
}

float			my_atof(const std::string& String)
{
  float			f;
  std::stringstream	ss(String);

  ss >> f;
  return (f);
}

std::string		my_upper(std::string String)
{
  std::transform(String.begin(), String.end(), String.begin(), ::toupper);
  return (String);
}
