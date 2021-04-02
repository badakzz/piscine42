all: libft

libft: objects.o
	ranlib libft.a

objects.o: functions.c
	ar cr libft.a ft_atoi.o ft_iterative_power.o ft_putchar.o ft_putnbr.o ft_putstr.o ft_strcpy.o ft_strlen.o ft_swap.o ft_putnbr_and_nl.o ft_strstr.o ft_strcmp.o ft_delete_whitespaces.o

functions.c: objects.o
	gcc -c -Wall -Werror -Wextra srcs/ft_atoi.c srcs/ft_iterative_power.c srcs/ft_putchar.c srcs/ft_putnbr.c srcs/ft_putstr.c srcs/ft_strcpy.c srcs/ft_strlen.c srcs/ft_swap.c srcs/ft_putnbr_and_nl.c srcs/ft_strstr.c srcs/ft_strcmp.c srcs/ft_delete_whitespaces.c

clean: 
	rm ft_atoi.o ft_iterative_power.o ft_putchar.o ft_putnbr.o ft_putstr.o ft_strcpy.o ft_strlen.o ft_swap.o ft_putnbr_and_nl.o ft_strstr.o ft_strcmp.o ft_delete_whitespaces.o

fclean:
	rm -f ft_atoi.o ft_iterative_power.o ft_putchar.o ft_putnbr.o ft_putstr.o ft_strcpy.o ft_strlen.o ft_swap.o ft_putnbr_and_nl.o ft_strstr.o ft_strcmp.o ft_delete_whitespaces.o

re:
	fclean all