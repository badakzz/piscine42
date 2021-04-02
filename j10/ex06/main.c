#include <unistd.h>

int sum(int a, int b);
int subtract(int a, int b);
int mul(int a, int b);
int div(int a, int b);
int (*p[4]) (int x, int y);

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
  if (nb < 0)
  {
    ft_putchar('-');
    nb = -nb;
  }
  if (nb / 10 == 0)
    ft_putchar(nb + '0');
  else
  {
    while (nb / 10 > 0)
    {
      ft_putchar((nb % 10) + '0');
      nb = nb / 10;
    }
  }
  return;
}

int   main (int argc, char **argv)
{
  int i;
  int j;
  int result;
  p[0] = sum;
  p[1] = subtract;
  p[2] = mul;
  p[3] = div;

  i = ft_atoi(argv[1]);
  j = ft_atoi(argv[3]);
  if (argc != 4)
    return (0);
  if (ft_strlen(argv[2]) == 1 && is_a_valid_operator(argv[2])
    && is_a_number(argv[1]) == 1
    && is_a_number(argv[3]) == 1)
  {
    if (argv[2][0] == '+')
    {
      result = (*p[0])(i, j);
      write_number(result);
    }
    else if (argv[2][0] == '-')
    {
      result = (*p[1])(i, j);
      write_number(result);
    }
    else if (argv[2][0] == '*')
    {
      result = (*p[2])(i, j);
      write_number(result);
    }
    else if (argv[2][0] == '/')
    {
      result = (*p[3])(i, j);
      write_number(result);
    }
    ft_putchar('\n');
  }
  else
  {
    ft_putchar('0');
    ft_putchar('\n');
  }
  return (0);
}

int   sum(int a, int b)
{
  return (a + b);
}

int   subtract(int a, int b)
{
  return (a - b);
}

int    mul(int a, int b)
{
  return (a * b);
}

int   div(int a, int b)
{
  if(b) 
    return (a / b);
  else 
    return (0);
}