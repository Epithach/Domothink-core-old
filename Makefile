
################
# Server Rules #
################

NAME_SERVER	= server

INC_SERVER	= ./Server/include

SRC_SERVER	= ./Server/main.cpp			\
			  ./Server/utils.cpp		\
			  ./Server/exception.cpp	\
			  ./Server/server.cpp		\

OBJ_SERVER	= $(SRC_SERVER:.cpp=.o)

################
# Client Rules #
################

NAME_CLIENT	= client

INC_CLIENT	= ./Client/include

SRC_CLIENT	= ./Client/main.cpp			\
			  ./Client/utils.cpp		\
			  ./Client/exception.cpp	\
			  ./Client/client.cpp		\

OBJ_CLIENT	= $(SRC_CLIENT:.cpp=.o)

######################
# Compilations Rules #
######################

RM			= rm -rf

CXX			= cl ##g++

CXXFLAGS	= -W -Wall -Wextra -Werror

LDFLAGS		= -lboost_system -lpthread -lboost_filesystem -lboost_thread

###########
# Targets #
###########

all : $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER) :	$(OBJ_SERVER)
	$(CXX) -o $(NAME_SERVER) $(OBJ_SERVER) $(LDFLAGS)

$(NAME_CLIENT) :	$(OBJ_CLIENT)
	$(CXX) -o $(NAME_CLIENT) $(OBJ_CLIENT) $(LDFLAGS)

clean :
	$(RM) $(OBJ_SERVER) $(OBJ_CLIENT)

fclean : clean
	$(RM) $(NAME_SERVER) $(NAME_CLIENT)

re : all clean

.PHONY : all re clean fclean