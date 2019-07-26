#include <string.h>
#include "ft_btree_rb.h"
#include "ft_list.h"
#include <stdio.h>

int main()
{
	t_rb_node *root = 0;

/*	b_in(&root, "6", (int(*)(void *, void *))strcmp);
	b_in(&root, "7", (int(*)(void *, void *))strcmp);
	b_in(&root, "4", (int(*)(void *, void *))strcmp);
	b_in(&root, "3", (int(*)(void *, void *))strcmp);
	b_in(&root, "5", (int(*)(void *, void *))strcmp);
	b_in(&root, "2", (int(*)(void *, void *))strcmp);*/

	
	rb_insert(&root, "2", (int(*)(void *, void *))strcmp);
	rb_insert(&root, "5", (int(*)(void *, void *))strcmp);
	rb_insert(&root, "4", (int(*)(void *, void *))strcmp);
	rb_insert(&root, "1", (int(*)(void *, void *))strcmp);
	rb_insert(&root, "3", (int(*)(void *, void *))strcmp);

	btree_apply_by_level(root, (void(*)(void *, int, int))printf);
}
