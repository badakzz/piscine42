#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>

t_list	*ft_create_elem(void *data)
{
	t_list *t_list_elem;

	t_list_elem = NULL;
	t_list_elem = malloc(sizeof(t_list));
	t_list_elem->data = data;
	t_list_elem->next = NULL;
	return (data);
}

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*list;

	list = *begin_list;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = ft_create_elem(data);
	}
	else
		*begin_list = ft_create_elem(data);
}

int		main(void)
{
	int a;
	int b;
	void *data;
	void *data2;
	int i;

	a = 7;
	b = 8;
	data = &a;
	data2 = &b;
	i = 0;
	t_list **begin_list = malloc(sizeof(t_list) * 4);
	begin_list[0] = ft_create_elem(data);
	begin_list[1] = ft_create_elem(data);
	begin_list[2] = ft_create_elem(data);

	printf("premiere liste\n");
	while (i < 3)
	{
		printf("%p\n", begin_list[i]->data);
		i++;
	}
	printf("deuxieme liste\n");
	ft_list_push_back(begin_list, data2);
	i = 0;
		while (i < 4)
	{
		printf("%p\n", begin_list[i]);
		i++;
	}
}