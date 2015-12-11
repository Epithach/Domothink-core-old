NAME		= mysql

SRC		= mySql.cpp	\

OBJ		= $(SRC:.cpp=.o)

CXX		= g++

RM		= rm -rf

CXXFLAGS		= -I/usr/local/include -I/usr/local/include/cppconn -Llibboost/boost_1_59_0 -lmysqlcppconn ##-Werror -W -Wall -Wextra -lm     

all:		$(NAME)

$(NAME) :        $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(CXXFLAGS)
clean :
	$(RM) $(OBJ)
fclean : clean
	$(RM) $(NAME)
re : $(NAME) clean

.PHONY : all re clean fclean
