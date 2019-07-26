/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjiseong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 05:55:32 by sjiseong          #+#    #+#             */
/*   Updated: 2019/07/26 06:31:50 by sjiseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

void	apply_func(t_btree **curr_lev, int lev, int len,
		void (*applyf)(void *item, int current_level, int is_first_elem))
{
	int	i;

	i = 0;
	while (i < len)
	{
		applyf(curr_lev[i]->item, lev, i ? 0 : 1);
		i++;
	}
}

void	btree_apply_from_level1(t_btree **pre_lev, t_btree **curr_lev,
		int *arr,
		void (*applyf)(void *item, int current_level, int is_first_elem))
{
	int	i;
	int	j;

	curr_lev = (t_btree**)malloc(sizeof(t_btree*) * arr[1]);
	i = 0;
	j = 0;
	while (i < arr[1] / 2)
	{
		if (pre_lev[i]->left)
			curr_lev[j++] = pre_lev[i]->left;
		if (pre_lev[i]->right)
			curr_lev[j++] = pre_lev[i]->right;
		i++;
	}
	if (!j)
		return ;
	apply_func(curr_lev, arr[0], j, applyf);
	free(pre_lev);
	pre_lev = curr_lev;
	arr[0]++;
	arr[1] = j * 2;
	btree_apply_from_level1(pre_lev, curr_lev, arr, applyf);
	return ;
}

void	btree_apply_by_level(t_btree *root,
		void (*applyf)(void *item, int current_level, int is_first_elem))
{
	int		lev;
	int		size;
	int		arr[2];
	t_btree **pre_lev;
	t_btree	**curr_lev;

	if (!root)
		return ;
	pre_lev = (t_btree**)malloc(sizeof(t_btree*));
	curr_lev = 0;
	pre_lev[0] = root;
	applyf(root->item, 0, 1);
	lev = 1;
	size = 2;
	arr[0] = lev;
	arr[1] = size;
	btree_apply_from_level1(pre_lev, curr_lev, arr, applyf);
	return ;
}
