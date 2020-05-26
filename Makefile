##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## wait..loading..
##

SRC	=	intersection.c

NAME	=	104intersection

all:	$(NAME)

$(NAME):
	make -C lib/my
	gcc -o $(NAME) $(SRC) -Llib/my -lmy -lm

clean:
	make -C lib/my clean

fclean:	clean
	rm -f $(NAME)
	make -C lib/my fclean

re:	fclean all
	make -C lib/my fclean all
