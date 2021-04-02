CC = gcc

NAME = ft_advanced_do-op

SRC = main.c ft_add.c ft_sub.c ft_div.c ft_mod.c ft_mul.c ft_usage.c errormod.c errordiv.c

OBJ = main.o ft_add.o ft_sub.o ft_div.o ft_mod.o ft_mul.o ft_usage.o errormod.o errordiv.o

HEADERS = header.h ft_opp.h

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all