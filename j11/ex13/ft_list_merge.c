#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_print_list(t_list *list)
{
	while (list)
	{
		printf("%p\n", list);
		list = list->next;
	}
}   

t_list	*ft_create_elem(void *data)
{
	t_list	*list;

	list = NULL;
	list = malloc(sizeof(t_list));
	if (list)
	{
		list->data = data;
		list->next = NULL;
	}
	return (list);
}

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list *list;

	list = *begin_list1;
	if (list && begin_list2)
	{
		while (list->next)
			list = list->next;
		while(begin_list2)
		{
			list->next = begin_list2;
			list = list->next;
			begin_list2 = begin_list2->next;
		}
	}
}

int      main(void)
{
	char str1[] = "zebzi";
	char str2[] = "zebzo";
	char str3[] = "zebzii";
	int str4 = 12412;
	int str5 = 123;
	int str6 = 4;
	int str7 = 3;

	t_list *begin_list;
	t_list *begin_list2;
	begin_list = ft_create_elem(&str1);
	begin_list->next = ft_create_elem(&str2);
	begin_list->next->next = ft_create_elem(&str3);
	begin_list2 = ft_create_elem(&str4);
	begin_list2->next = ft_create_elem(&str5);
	begin_list2->next->next = ft_create_elem(&str6);
	begin_list2->next->next->next = ft_create_elem(&str7);


	printf("liste 1\n");
	ft_print_list(begin_list);
	printf("list 2\n");
	ft_print_list(begin_list2);
	printf("updated\n");
		ft_list_merge(&begin_list, begin_list2);

	ft_print_list(begin_list);
	return (0);
}