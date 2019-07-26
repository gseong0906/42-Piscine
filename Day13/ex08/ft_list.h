/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjiseong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 15:26:08 by sjiseong          #+#    #+#             */
/*   Updated: 2019/07/26 15:49:54 by sjiseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

void	rb_insert(struct s_rb_node **root, void *data,
		int (*cmpf)(void *, void *));
void	btree_apply_by_level(t_rb_node *root,
		void (*applyf)(void *item, int current_level, int is_first_elem));
#endif
