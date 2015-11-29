
################
# Server Rules #
################

NAME_SERVER	= server

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
						/D_WIN32_WINNT=0x0501 \
						/Wall \
						/c

# /WX	: treat all the linker warnings as errors
LDFLAGS		= /WX \
						/link /LIBPATH:.\deps\boost_1_59_0\lib32-msvc-14.0

# /Fo	: change name of the target (equivalent of the -o option, except that the
#				name is stick with the option)

.cpp.obj :
	$(CPP) $(CPPFLAGS) $< /Fo$@

###########
# Targets #
###########

all : $(NAME_SERVER)

$(NAME_SERVER) :	$(OBJ_SERVER)
	$(CXX) /Fo$(NAME_SERVER) $(OBJ_SERVER) $(LDFLAGS)

clean :
	$(RM) $(OBJ_SERVER)

fclean : clean
	$(RM) $(NAME_SERVER)

re : fclean all

.PHONY : all clean fclean re
