NAME_SERVER	= server

NAME_CLIENT	= client

SRC_SERVER	= ./Server/main.cpp \
		  ./Server/utils.cpp \

SRC_CLIENT	= ./Client/main.cpp \
		  ./Client/utils.cpp \

OBJ_SERVER	= $(SRC_SERVER:.cpp=.o)

OBJ_CLIENT	= $(SRC_CLIENT:.cpp=.o)

GPP		= g++

RM		= rm -rf

FLAG		= -lboost_system -lpthread -lboost_filesystem -lboost_thread ##-Werror -W -Wall -Wextra -lm

all:		$(NAME_CLIENT) $(NAME_SERVER)

$(NAME_SERVER) :	$(OBJ_SERVER)
	$(CC) -o $(NAME_SERVER) $(OBJ_SERVER) $(FLAG)
$(NAME_CLIENT) :	$(OBJ_CLIENT)
	$(CC) -o $(NAME_CLIENT) $(OBJ_CLIENT) $(FLAG)
clean :
	$(RM) $(OBJ_SERVER) $(OBJ_CLIENT)
fclean : clean
	$(RM) $(NAME_SERVER) $(NAME_CLIENT)
re : all clean

.PHONY : all re clean fclean