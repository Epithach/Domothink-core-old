NAME		= postgre

SRC_CLIENT	= ./src/main.cpp \
		  ./IdataBase.cpp \

OBJ		= $(SRC:.cpp=.o)

CC		= g++

RM		= rm -rf

FLAG		= -lpqxx -lpq ##-Werror -W -Wall -Wextra -lm     

all:		$(NAME)

$(NAME) :        $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(FLAG)
clean :
	$(RM) $(OBJ) $(OBJ)
fclean : clean
	$(RM) $(NAME)
re : all clean

.PHONY : all re clean fclean