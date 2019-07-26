/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjiseong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 03:20:12 by sjiseong          #+#    #+#             */
/*   Updated: 2019/07/26 03:56:04 by sjiseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
		int (*cmpf)(void *, void *))
{
	void	*tmp;

	if (!root)
		return (0);
	tmp = btree_search_item(root->left, data_ref, cmpf);
	if (tmp)
		return (tmp);
	if (cmpf(data_ref, root->item) == 0)
		return (root->item);
	tmp = btree_search_item(root->right, data_ref, cmpf);
	if (tmp)
		return (tmp);
	return (0);
}
