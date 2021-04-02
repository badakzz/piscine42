#ifndef HEADER_H
# define HEADER_H

#include <unistd.h>
#include <stdlib.h>

typedef int	(*t_func_opp)(int, int);

typedef struct s_opp {
   char *operator;
   t_func_opp func;
} t_opp;

int ft_add(int a, int b);
int ft_sub(int a, int b);
int ft_mul(int a, int b);
int ft_div(int a, int b);
int ft_mod(int a, int b);
int ft_usage(int a, int b);
int errordiv(void);
int errormod(void);

#endif