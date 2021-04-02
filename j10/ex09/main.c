#include <unistd.h>
#include "header.h"
#include "ft_opp.h"

void  ft_putchar(char c)
{
  write (1, &c, 1);
}

int   ft_atoi(char *str)
{
  int i;
  int n;
  int neg;

  i = 0;
  n = 0;
  neg = 0;
  if (str[i] == 45)
  {
    neg = 1;
    i++;
  }
  while (str[i])
  {
    n = n * 10;
    n = n + (str[i] - '0');
    i++;  
  }
  if (neg == 1)
    return (-n);
  else
    return (n);
}

int   ft_strlen(char *str)
{
  int length;

  length = 0;

  while (*str++)
  {
    length++;
  }
  return (length);
}

int   is_a_valid_operator(char *str)
{
  if (str[0] == '+' || str[0] == '-' || str[0] == '/' ||
        str[0] == '*' || str[0] == '%')
    return (1);
  else
    return (0);
}

int  is_a_number(char *str)
{
  int i;
  int bool;

  i = 0;
  bool = 0;
  if (str[0] == '-')
    i++;
  while (str[i])
  {
    if (str[i] <= 57 && str[i] >= 48)
      bool = 1;
    i++;
  }
  if (bool == 1)
    return (1);
  return (0);
}

void  write_number(int nb)
{
  int nbinit;
  int size;

  size = 1;

  if (nb < 0)
  {
    ft_putchar('-');
    nb = nb * -1;
  }
  nbinit = nb;
  while(nbinit / 10 > 0)
  {
    nbinit = nbinit / 10;
    size = size * 10;
  }
  nbinit = nb;
  while(size > 0)
  {
    ft_putchar((nbinit / size) + '0');
    nbinit = nbinit % size;
    size = size / 10;
  }
  return;
}

int   main (int argc, char **argv)
{
  int i;
  int j;
  long unsigned int k;
  int result;

  i = ft_atoi(argv[1]);
  j = ft_atoi(argv[3]);
  k = 0;
  if (argv[2][0] == '/' && j == 0)
    return (errordiv());
  if (argv[2][0] == '%' && j == 0)
    return (errormod());
  if (argc != 4)
    return (0);
  if (ft_strlen(argv[2]) == 1 && is_a_valid_operator(argv[2])
    && is_a_number(argv[1]) == 1
    && is_a_number(argv[3]) == 1)
  {
    while(k <= ((sizeof(gl_opptab) / sizeof(t_opp))) - 1)
    {
    if (argv[2][0] == gl_opptab[k].operator[0])
    {
      result = gl_opptab[k].func(i, j);
      write_number(result);
      ft_putchar('\n');
      return (0);
    }
    k++;
  }
}
  gl_opptab[5].func(i, j);
  return (0);
}
