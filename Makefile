
################
# Server Rules #
################

NAME_SERVER	= server.exe

INC_SERVER	= .\Server\include

SRC_SERVER	= .\Server\main.cpp			\
			  .\Server\utils.cpp		\
			  .\Server\exception.cpp	\
			  .\Server\server.cpp		\

OBJ_SERVER	= $(SRC_SERVER:.cpp=.obj)

######################
# Compilations Rules #
######################

RM			= del

CPP			= cl

# /EHsc : to enable exceptions handling
# /I		: to add new path to the includes directories
# /D		: add macro definition
#					WIN32_WINNT=0x0501 needed by boost, suggested by cl.exe
# /Wall	: enable all the warnings (enable all /W4 and other warnings that are of
#					by default)
# /WX		: treat all the compiler warnings as errors
# /c		: only built .obj file (do not link them)
CPPFLAGS	= /EHsc \
						/I .\deps\boost_1_59_0 /I .\Server\include	\
						/I .\test\mysql\mysql-connector-c++-1.1.6 \
						/D_WIN32_WINNT=0x0501 \
						/MD .\test\mysql\mysql-connector-c++-1.1.6\libmysqlcppconn\ \
						/Wall \
						/c

# /WX	: treat all the linker warnings as errors
#						/LIBPATH:.\test\mysql\mysql-connector-c++-1.1.6\libmysql \
#						/LIBPATH:.\test\mysql\mysql-connector-c++-1.1.6\libmysqlcppconn
#						/MD .\test\mysql\mysql-connector-c++-1.1.6\libmysql\libmysql.lib \
LDFLAGS		= /WX \
						/link /LIBPATH:.\deps\boost_1_59_0\lib32-msvc-14.0 \
#						LIBPATH:.\test\mysql\mysql-connector-c++-1.1.6\libmysqlcppconn\ \
#						/LIBPATH:"C:\Program Files (x86)\MySQL\MySQL Server 5.7\lib" \
#						/LIBPATH:"C:\Program Files (x86)\MySQL\MySQL Connector C++ 1.1.6\lib\opt" \

STATIC_LIB	= .\test\mysql\mysql-connector-c++-1.1.6\libmysql\libmysql.lib \
			  .\test\mysql\mysql-connector-c++-1.1.6\libmysqlcppconn\mysqlcppconn.lib \

# /Fo	: change name of the target (equivalent of the -o option, except that the
#				name is stick with the option)
.cpp.obj :
	$(CPP) $(CPPFLAGS) $< /Fo$@

###########
# Targets #
###########

all : $(NAME_SERVER)

$(NAME_SERVER) :	$(OBJ_SERVER)
	$(CXX) /Fo$(NAME_SERVER) $(OBJ_SERVER) $(LDFLAGS) $(STATIC_LIB) 

clean :
	$(RM) $(OBJ_SERVER)

fclean : clean
	$(RM) $(NAME_SERVER)

re : fclean all

.PHONY : all clean fclean re
