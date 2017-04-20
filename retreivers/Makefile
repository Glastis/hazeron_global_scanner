SRC=	        common/get_page.c \
                common/utilities.c \
			    online_players/get_online_players.c \
			    online_players/number_online_players.c \

OBJ=			$(SRC:.c=.o)

NAME=			a.out

CFLAGS=			-Wall -Wextra -g3

LFLAGS=			-lcurl

all:			$(NAME)

$(NAME):		$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LFLAGS)

clean:
	rm -f $(OBJ)

fclean:			clean
	rm -f $(NAME)

re:			fclean all

.PHONY:	all clean fclean re
