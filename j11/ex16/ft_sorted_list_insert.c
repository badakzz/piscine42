#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>

void    ft_print_list(t_list *list)
{
    while (list)
    {
        printf("%p\n", list);
        list = list->next;
    }
}

void    ft_print_list_data(t_list *list)
{
    while (list)
    {
        printf("%p\n", list->data);
        list = list->next;
    }
}

t_list  *ft_create_elem(void *data)
{
    t_list  *list;

    list = NULL;
    list = malloc(sizeof(t_list));
    if (list)
    {
        list->data = data;
        list->next = NULL;
    }
    return (list);
}

int ft_list_size(t_list *begin_list)
{
    t_list  *list;
    int     i;

    i = 0;
    list = begin_list;
    while (list)
    {
        list = list->next;
        i++;
    }
    return (i);
}

void    ft_sorted_list_insert(t_list **begin_list, void *data, int(*cmp)())
{
    t_list  *current;
    t_list  *new_node;

    new_node = ft_create_elem(data);
    if (*begin_list == NULL || (*cmp)((*begin_list)->data, new_node->data) > 0)
    {
        new_node->next = *begin_list;
        *begin_list = new_node;
    }
    else
    {
        current = *begin_list;
        while (current->next != NULL && (*cmp)(new_node->data, current->data) < 0)
            current = current->next;
        new_node->next = current->next;
        current->next = new_node;
    }
}

int     ft_strcmp(char *s1, const char *s2)
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
    char str2[] = "b";
    char str3[] = "d";
    char str4[] = "e";
    char str5[] = "f";
    char str6[] = "g";
    char str7[] = "h";
    char str[] = "c";

    t_list *begin_list;
    begin_list = ft_create_elem(&str1);
    begin_list->next = ft_create_elem(&str2);
    begin_list->next->next = ft_create_elem(&str3);
    begin_list->next->next->next = ft_create_elem(&str4);
    begin_list->next->next->next->next = ft_create_elem(&str5);
    begin_list->next->next->next->next->next = ft_create_elem(&str6);
    begin_list->next->next->next->next->next->next = ft_create_elem(&str7);


    printf("liste\n");
    printf("%d\n", ft_strcmp(str1, str));
    ft_print_list(begin_list);
    ft_sorted_list_insert(&begin_list, str, &ft_strcmp);
    printf("updated\n");
    ft_print_list(begin_list);
    return (0);
}