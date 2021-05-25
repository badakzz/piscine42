#include "ft_btree.h"

int		btree_level_count(t_btree *root)
{
    int level;
    int level2;

    if (!root)
        return (0);
    level = btree_level_count(root->left);
    level2 = btree_level_count(root->right);
    if (level2 > level)
        level = level2;
    return (1 + level);
}