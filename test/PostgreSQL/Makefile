NAME		= postgre

SRC		= ./src/main.cpp	\
		  ./src/exception.cpp	\
		  ./src/postgre.cpp	\

OBJ		= $(SRC:.cpp=.o)

GPP		= g++

RM		= rm -rf

FLAG		= -lpq -I/usr/local/pgsql/include ##-Werror -W -Wall -Wextra -lm     

all:		$(NAME)

$(NAME) :        $(OBJ)
	$(GPP) -o $(NAME) $(OBJ) $(FLAG)
clean :
	$(RM) $(OBJ)
fclean : clean
	$(RM) $(NAME)
re : $(NAME) clean

.PHONY : all re clean fclean