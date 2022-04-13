##
## EPITECH PROJECT, 2021
## Pushswap
## File description:
## semestre1
##

SRC			=	src/lib/my_getnbr.c\
				src/lib/my_put_nbr.c\
				src/lib/my_putchar.c\
				src/lib/my_putstr.c\
				src/lib/my_strcat.c\
				src/lib/my_strcmp.c\
				src/lib/my_strcpy.c\
				src/lib/my_strlen.c\
				src/attack.c\
				src/check_error_maps.c\
				src/check_error.c\
				src/connect.c\
				src/create_maps.c\
				src/game.c\
				src/global.c\
				src/init.c\
				src/maps.c\
				src/signal.c\
				src/waiting.c\

SRC_MAIN	=	src/main.c\

SRC_TEST	=	tests/test.c

OBJ	=	$(SRC:.c=.o)

OBJ2	=	$(SRC_TEST:.c=.o)

OBJ3	=	$(SRC_MAIN:.c=.o)

NAME	=	navy

CPPFLAGS	=	-I ./include/

CFLAGS	+=	-Wall -Wextra -g

CRIT_FLAGS	=	--coverage -lcriterion

NAME_TEST	=	unit_test

all: $(NAME)

$(NAME): $(OBJ) $(OBJ3)
	gcc -o $(NAME) $(OBJ) $(OBJ3) $(LIB_FLAGS)

clean:
	rm -f $(OBJ) $(OBJ3)
	rm -f -r *~
	rm -f *gc*

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_TEST)

unit_test: $(OBJ) $(OBJ2)
	gcc -o $(NAME_TEST) $(SRC) $(SRC_TEST) $(CPPFLAGS) $(CFLAGS) $(LIB_FLAGS) $(CRIT_FLAGS)

tests_run: unit_test
	./$(NAME_TEST)
	gcovr --exclude tests/
	gcovr -b --exclude tests/

re: fclean all

.PHONY: all clean fclean unit_test tests_run re