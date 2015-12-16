
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

CXX		= g++

CXXFLAGS	= -W -Wall -Wextra -Werror \
						-I ./Server/include

LDFLAGS		= -lboost_system -lpthread -lboost_filesystem -lboost_thread

###########
# Targets #
###########

all : $(NAME_CLIENT)

$(NAME_CLIENT) :	$(OBJ_CLIENT)
	$(CXX) $(EXEC) $(OBJ_CLIENT) $(LDFLAGS)

clean :
	$(RM) $(OBJ_SERVER) $(OBJ_CLIENT)

fclean : clean
	$(RM) $(NAME_SERVER) $(NAME_CLIENT)

re : fclean all

.PHONY : all clean fclean re
