#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>


void    ft_print_list(t_list *list)
{
    while (list)
    {
        printf("%p\n", list->data);
        list = list->next;
    }
}  

void    ft_print_list_data(t_list *list)
{
    while (list)
    {
        printf("%p\n", list);
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
void    ft_list_reverse_fun(t_list *begin_list)
{
    int     count;
    int     i;
    int     j;
    t_list  *current;
    void    *tmp;

    count = 0;
    current = begin_list;
    while (current && ++count)
        current = current->next;
    i = 0;
    while (i < count - 1)
    {
        j = i;
        current = begin_list;
        while (current && current->next && j < count - 1)
        {
            tmp = current->data;
            current->data = current->next->data;
            current->next->data = tmp;
            current = current->next;
            ++j;
        }
        ++i;
    }
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
    ft_print_list(begin_list);
    ft_list_reverse_fun(begin_list);
    printf("updated\n");
    ft_print_list(begin_list);
    return (0);
}