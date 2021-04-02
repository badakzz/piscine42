#include <stdio.h>

int 	ft_antidote(int i, int j, int k)
{
	if ((i < j && i > k) || (i > j && i < k))
		return i;
	else if ((j < i && j > k) || (j > i && j < k))
		return j;
	return k;
}

int 	main()
{
	printf("%d", ft_antidote(4, 1, 3));
}