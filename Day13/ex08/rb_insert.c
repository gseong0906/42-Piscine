/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjiseong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 06:41:41 by sjiseong          #+#    #+#             */
/*   Updated: 2019/07/26 16:52:37 by sjiseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree_rb.h"
#include <stdlib.h>

void		rb_change_position(t_rb_node *parent,
		t_rb_node *left, t_rb_node *right)
{
	parent->color = RB_BLACK;
	left->color = RB_RED;
	right->color = RB_RED;
	parent->left = left;
	parent->right = right;
	left -> parent = parent;
	right -> parent = parent;
	if (left->left == parent)
		left->left = 0;
	if (left->right == parent)
		left->rifht = 0;
	if (right->left == parent)
		right->left = 0;
	if (right->right == parent)
		right->right = 0;
	return ;
}

void		switch_node(t_rb_node	*nodes, int i, int j)
{
	t_rb_node	*tmp;

	tmp = nodes[i];
	nodes[i] = nodes[j];
	nodes[j] = tmp;
	return ;
}

void		rb_restruct(t_rb_node *root,
		int (*cmpf)(void *, void *), t_rb_node *parent)
{
	t_rb_node	nodes[3];

	nodes[0] = root;
	nodes[1] = root->parent;
	nodes[2] = root->parent->parent;
	if (cmpf(nodes[0]->item, nodes[1]->item) > 0)
		switch_node(nodes, 0, 1);
	if (cmpf(nodes[0]->item, nodes[2]->item) > 0)
		switch_node(nodes, 0, 2);
	if (cmpf(nodes[1]->item, nodes[2]->item) > 0)
		switch_node(nodes, 1, 2);
	rb_change_position(nodes[1], nodes[0], nodes[2]);
	return ;
}

void		rb_recolor(t_rb_node *root)

void		double_red(t_rb_node *root,
		int (*cmpf)(void *, void *), t_rb_node *parent)
{
	t_rb_node	*uncle;

	if (!(root)->parent)
	{
		(root)->color = RB_BLACK;
		return ;
	}
	else if (!(root)->parent->parent || (root)->parent->color == RB_BLACK)
		return ;
	if ((root)->parent == (root)->parent->parent->left)
		uncle = (root)->parent->parent->right;
	else
		uncle = (root)->parent->parent->left;
	if (!uncle || uncle->color == RB_BLACK)
		rb_restruct(root, cmpf);
	else
	{
		rb_recolor(root);
		double_red(root);
	}
	return;
}

t_rb_node		*rb_create_node(void *item, t_rb_node *parent)
{
	t_rb_node	*node;

	node = (t_rb_node*)malloc(sizeof(t_rb_node));
	node->left = 0;
	node->right = 0;
	node->parent = parent;
	node->color = RB_RED;
	node->item = item;
	return (node);
}

t_rb_node	*btree_insert_data(t_rb_node **root, void *item,
		int (*cmpf)(void *, void *), t_rb_node *parent)
{
	t_rb_node	*tmp;

	if (!*root)
	{
		*root = rb_create_node(item, parent);
		return (*root);
	}
	parent = *root;
	if (cmpf(item, (*root)->item) < 0)
	{
		tmp = btree_insert_data(&(*root)->left, item, cmpf, parent);
		if (tmp)
			return (tmp);
	}
	else
		return (btree_insert_data(&(*root)->right, item, cmpf, parent));
	return (0);
}

void			rb_insert(struct s_rb_node **root, void *data,
		int (*cmpf)(void *, void *))
{
	t_rb_tree	*node;

	node = btree_insert_data(root, data, cmpf, 0);
	if (!(node->parent) || node->parent->color == RB_RED)
		double_red(node, cmpf);
	return ;
}
