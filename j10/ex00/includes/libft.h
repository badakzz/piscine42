#ifndef LIBFT_H
#define LIBFT_H

int 	ft_atoi(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
void 	ft_putnbr_and_nl(int nb);
int 	ft_strlen(char *str);
int 	ft_iterative_power(int nb, int power);
char 	*ft_strcpy(char *dest, char *src);
void 	ft_swap(int *a, int *b);
void 	ft_putstr(char *str);
char	*ft_strstr(char *str, char *to_find);
char	*ft_delete_whitespaces(char *str);
int		ft_strcmp(char *s1, char *s2);

#endif