#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>

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

t_list  *ft_list_foreach_if(t_list *begin_list, void *data_ref, int (*cmp)())
{
    t_list  *list_ptr;

    list_ptr = begin_list;
    while (list_ptr)
    {
        if ((*cmp)(list_ptr->data, data_ref) == 0)
            return (list_ptr->data);
        list_ptr = list_ptr->next;
    }
    return (NULL);
}

void ft_print_list_data(t_list *list)
{
    while (list)
    {
        printf("%p\n", list->data);
        list = list->next;
    }
}   

int ft_strcmp(char *s1, const char *s2)
{
    int x;

    x = 0;
    while (s1[x] == s2[x] && s1[x] != '\0' && s2[x] != '\0')
        x++;
    return (s1[x] - s2[x]);
}

void     ft_add2(void *data)
{
    data = data + 2;
    return;
}

int        main(void)
{
    char str[] = "zebxi";
    char str2[] = "zebzi";
    char str3[] = "zebxi";
    char str4[] = "zebi";

    t_list *begin_list;
    begin_list = ft_create_elem(&str2);
    begin_list->next = ft_create_elem(&str3);
    begin_list->next->next = ft_create_elem(&str4);

    printf("liste\n");
    ft_print_list_data(begin_list);
    printf("pog\n");
    printf("%p", ft_list_foreach_if(begin_list, str, &ft_strcmp));
    return (0);
}