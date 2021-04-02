#include <stdio.h>

void	ft_takes_places(int hour)
{

	if(hour >= 12)
		hour -= 12;
	if(hour == 9)
		printf("THE FOLLOWING TAKES PLACE BETWEEN 0%d.00 A.M. AND %d.00 A.M.\n", hour, hour + 1);
	else
	{
		if(hour >= 10)
			printf("THE FOLLOWING TAKES PLACE BETWEEN %d.00 A.M. AND %d.00 A.M.\n", hour, hour + 1);
		else
			printf("THE FOLLOWING TAKES PLACE BETWEEN 0%d.00 A.M. AND 0%d.00 A.M.\n", hour, hour + 1);
	}
	return;
}

int 	main(void)
{
	int hour;

	hour = 11;
	ft_takes_places(hour);
}