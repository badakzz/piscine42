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

t_list	*delete_node (t_list **begin_list)
{
	t_list *list;
	t_list *temp;
	list = *begin_list;
	temp = list->next;
	list->next = temp->next;
	free(temp);
	return (list);
}

void	delete_first_node(t_list **begin_list)
{
	t_list	*temp;
	t_list	*list_ptr;
	list_ptr = *begin_list;
	temp = list_ptr->next;
	*begin_list = temp;
	free(list_ptr);
	return;
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list  *list_ptr;
	t_list	*prev;
	t_list	*temp;
	t_list	*last_node;

	list_ptr = *begin_list;
	prev = list_ptr;
	if (*begin_list)
	{

		while((*cmp)(list_ptr->data, data_ref) == 0 && list_ptr->next)
		{
			list_ptr = *begin_list;
			if ((*cmp)(list_ptr->data, data_ref) == 0 && list_ptr->next == NULL)
			{
				*begin_list = NULL;

				return;
			}
		}
		while (list_ptr)
		{
			if(list_ptr->next)
			{
				if ((*cmp)(list_ptr->next->data, data_ref) == 0)
				{
					if((*begin_list)->next == NULL )
					{
						*begin_list = NULL;
						return;
					}
					else
					{
						temp = *begin_list;
						while(temp->next->next != NULL)
							temp = temp->next;
						if ((*cmp)(temp->next->data, data_ref) == 0)
						{
							last_node = temp->next;
							temp->next = NULL;
							free(last_node);
						}
					}
				}
			}
			if ((*cmp)(list_ptr->data, data_ref) == 0)
				list_ptr = delete_node(&prev);
			prev = list_ptr;
			list_ptr = list_ptr->next;
		}

	}
}

int		ft_strcmp(char *s1, const char *s2)
{
	int x;

	x = 0;
	while (s1[x] == s2[x] && s1[x] != '\0' && s2[x] != '\0')
		x++;
	return (s1[x] - s2[x]);
}

int      main(void)
{
	char str[] = "zebxi";
	char str2[] = "zebzi";
	char str3[] = "zebzii";
	char str4[] = "zebxi";
	char str5[] = "zebxi";
	char str6[] = "zebx=zi";
	char str7[] = "zebz	i";

	t_list *begin_list;
	begin_list = ft_create_elem(&str2);
	begin_list->next = ft_create_elem(&str3);
	begin_list->next->next = ft_create_elem(&str4);
	begin_list->next->next->next = ft_create_elem(&str5);
	begin_list->next->next->next->next = ft_create_elem(&str6);
	begin_list->next->next->next->next->next = ft_create_elem(&str7);


	printf("liste\n");
	ft_print_list(begin_list);
	ft_list_remove_if(&begin_list, str, &ft_strcmp);
	printf("updated\n");
	ft_print_list(begin_list);
	return (0);
}