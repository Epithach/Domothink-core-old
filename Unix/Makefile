
################
# Server Rules #
################

NAME_SERVER	= server

INC_SERVER	= ./Server/include

SRC_SERVER	= ./Server/main.cpp			\
			  ./Server/utils.cpp		\
			  ./Server/exception.cpp	\
			  ./Server/server.cpp		\

######################
# Compilations Rules #
######################

RM			= rm -rf

CXX		= g++

CXXFLAGS	= -W -Wall -Wextra -Werror \
						-I ./Server/include

LDFLAGS		= -lboost_system -lpthread -lboost_filesystem -lboost_thread

###########
# Targets #
###########

all : $(NAME_SERVER)

$(NAME_SERVER) :	$(OBJ_SERVER)
	$(CXX) -o $(NAME_SERVER) $(OBJ_SERVER) $(LDFLAGS)

clean :
	$(RM) $(OBJ_SERVER)

fclean : clean
	$(RM) $(NAME_SERVER)

re : fclean all

.PHONY : all clean fclean re
