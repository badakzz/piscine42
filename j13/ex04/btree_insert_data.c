#include "ft_btree.h"

t_btree *btree_create_node(void *item)
{
  t_btree *btree;

  btree = NULL;
  btree = (t_btree*)malloc(sizeof(t_btree));
  if (btree)
  {
    btree->left = 0;
    btree->right = 0;
    btree->item = item;
  }
  return (btree);
}


void  btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *))
{
  if (*root == NULL)
    btree_create_node(item);
  else if ((*cmpf)(item, (*root)->item) < 0)
    btree_insert_data(&(*root)->left, item, cmpf);
  else
    btree_insert_data(&(*root)->right, item, cmpf);
}