#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>


void	ft_print_list_data(t_list *list)
{
	while (list)
	{
		printf("%p\n", list->data);
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

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
    t_list  *list_ptr;
    t_list  *next_node;
    void *temp;

    list_ptr = *begin_list;
    while (list_ptr)
    {
        next_node = list_ptr->next;
        while (next_node)
        {
            if ((*cmp)(list_ptr->data, next_node->data) > 0)
            {
                temp = list_ptr->data;
                list_ptr->data = next_node->data;
                next_node->data = temp;
            }
            next_node = next_node->next;
        }
        list_ptr = list_ptr->next;
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
	char str1[] = "a";
	char str2[] = "d";
	char str3[] = "c";
	char str4[] = "b";
	char str5[] = "g";
	char str6[] = "f";
	char str7[] = "e";

	t_list *begin_list;
	begin_list = ft_create_elem(&str1);
	begin_list->next = ft_create_elem(&str2);
	begin_list->next->next = ft_create_elem(&str3);
	begin_list->next->next->next = ft_create_elem(&str4);
	begin_list->next->next->next->next = ft_create_elem(&str5);
	begin_list->next->next->next->next->next = ft_create_elem(&str6);
	begin_list->next->next->next->next->next->next = ft_create_elem(&str7);


	printf("liste\n");
	ft_print_list_data(begin_list);
	ft_list_sort(&begin_list, &ft_strcmp);
	printf("updated\n");
	ft_print_list_data(begin_list);
	return (0);
}