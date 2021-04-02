#include <unistd.h>

#define _DECL
#define _INIT(x) = x

typedef int t_bool;
_DECL t_bool TRUE = 1;
_DECL t_bool FALSE = 0;
_DECL int SUCCESS = 1;

int EVEN(int nbr)
{
	if (nbr < 0)
		nbr = -nbr;
	if(nbr > 10)
	{
		while(nbr > 0)
		{
			nbr = nbr / 10;
		}
	}
	if(nbr == 1 || nbr == 3 || nbr == 7 || nbr == 9)
		return (0);
	else
		return (1);
}

_DECL char *EVEN_MSG = "J'ai un nombre pair d'arguments.\n";
_DECL char *ODD_MSG = "J'ai un nombre impair d'arguments.\n";