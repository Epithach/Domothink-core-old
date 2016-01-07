NAME		= postgre

SRC		= ./src/main.cpp		\
		  ./src/exception.cpp		\
		  ./src/postgre.cpp		\
##		  ../DataBaseException.cpp	\

OBJ		= $(SRC:.cpp=.o)

GPP		= g++

RM		= rm -rf

CXXFLAGS	= -I /usr/include/postgresql
FLAG		= -lpqxx  -lpq ##-Werror -W -Wall -Wextra -lm     

all:		$(NAME)

$(NAME) :        $(OBJ)
	$(GPP) -o $(NAME) $(OBJ) $(FLAG)
clean :
	$(RM) $(OBJ)
fclean : clean
	$(RM) $(NAME)
re : $(NAME) clean

.PHONY : all re clean fclean
