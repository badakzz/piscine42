#!/bin/sh

gcc -c -Wall -Werror -Wextra ft_atoi.c ft_iterative_power.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_strcpy.c ft_strlen.c ft_swap.c ft_putnbr_and_nl.c ft_strstr.c ft_strcmp.c ft_delete_whitespaces.c &&
ar cr libft.a ft_atoi.o ft_iterative_power.o ft_putchar.o ft_putnbr.o ft_putstr.o ft_strcpy.o ft_strlen.o ft_swap.o ft_putnbr_and_nl.o ft_strstr.o ft_strcmp.o ft_delete_whitespaces.o &&
ranlib libft.a