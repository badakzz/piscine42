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

void    ft_list_merge(t_list **begin_list1, t_list *begin_list2)
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
void    ft_list_sort(t_list **begin_list, int (*cmp)())
{
    t_list  *list_ptr;
    t_list  *next_node;
    void *temp;

    ft_print_list_data(*begin_list);
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

void    ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)())
{
    ft_list_merge(begin_list1, begin_list2);
    ft_list_sort(begin_list1, cmp);
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
    char str3[] = "c";
    char str4[] = "d";
    char str5[] = "e";
    char str6[] = "f";
    char str7[] = "g";
    char str8[] = "h";
    char str9[] = "i";
    char str10[] = "j";
    char str11[] = "k";
    char str12[] = "l";
    char str13[] = "m";
    char str14[] = "n";
    t_list *begin_list;
    t_list *begin_list2;
    begin_list2 = ft_create_elem(&str1);
    begin_list2->next = ft_create_elem(&str2);
    begin_list2->next->next = ft_create_elem(&str3);
    begin_list2->next->next->next = ft_create_elem(&str4);
    begin_list2->next->next->next->next = ft_create_elem(&str5);
    begin_list2->next->next->next->next->next = ft_create_elem(&str6);
    begin_list2->next->next->next->next->next->next = ft_create_elem(&str7);
    begin_list = ft_create_elem(&str8);
    begin_list->next = ft_create_elem(&str9);
    begin_list->next->next = ft_create_elem(&str10);
    begin_list->next->next->next = ft_create_elem(&str11);
    begin_list->next->next->next->next = ft_create_elem(&str12);
    begin_list->next->next->next->next->next = ft_create_elem(&str13);
    begin_list->next->next->next->next->next->next = ft_create_elem(&str14);

    printf("first list\n");
    ft_print_list_data(begin_list);
    printf("\n");
    printf("second list\n");
    ft_print_list_data(begin_list2);
    printf("\n");
    ft_sorted_list_merge(&begin_list, begin_list2, &ft_strcmp);
    printf("updated\n");
    ft_print_list_data(begin_list);
    return (0);
}