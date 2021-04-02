#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_create_elem(void *data)
{
	t_list *t_list_elem;

	t_list_elem = NULL;
	t_list_elem = malloc(sizeof(t_list));
	t_list_elem->data = data;
	t_list_elem->next = NULL;
	return (data);
}