SRC=	        	retreivers/common/get_page.c \
			retreivers/common/utilities.c \
			retreivers/online_players/get_online_players.c \
			retreivers/online_players/number_online_players.c \
			retreivers/fetch_player_data.c \

INC_PATH=		-I./includes/

OBJ=			$(SRC:.c=.o)

NAME=			a.out

CFLAGS=			-Wall -Wextra -g3 $(INC_PATH)

LFLAGS=			-lcurl

all:			$(NAME)

$(NAME):		$(OBJ)
	gcc -o $(NAME) $(INC_PATH) $(OBJ) $(LFLAGS)

clean:
	rm -f $(OBJ)

fclean:			clean
	rm -f $(NAME)

re:			fclean all

.PHONY:	all clean fclean re
