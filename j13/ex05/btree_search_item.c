#include "ft_btree.h"
#include <stddef.h>

void	*btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *))
{
	if (!(root))
		return (NULL);
	else
	{
		btree_search_item(root->left, data_ref, cmpf);
		if ((*cmpf)(data_ref, root->item) == 0)
			return (root->item);
		btree_search_item(root->right, data_ref, cmpf);
	}
}