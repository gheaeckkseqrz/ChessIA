NAME	=	ChessIA

SRC	=	main.cpp			\
		ChessBoard.cpp			\
		GameData.cpp			\
		PieceInfo.cpp			\
		PieceFactory.cpp		\
		Pawn.cpp			\
		Bishop.cpp			\
		Knight.cpp			\
		Rook.cpp			\
		King.cpp			\
		Queen.cpp			\
		Move.cpp			\
		MinMax.cpp			\
		RatedMove.cpp			\
		OptionsParser.cpp		\
		UCI.cpp				\
		Threadable.cpp			\
		Mutex.cpp			\
		LogManager.cpp

OBJ	=	$(SRC:.cpp=.o)

INCLUDE	=

LIB	=	-lboost_program_options -lpthread

CC	=	g++

CXXFLAGS +=	-Wall -Wextra -Werror --std=c++11
CXXFLAGS +=	-g $(INCLUDE)

LFLAG	+=	$(INCLUDE) $(LIB)

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LFLAG) $(INCLUDE)
clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		re clean fclean all
