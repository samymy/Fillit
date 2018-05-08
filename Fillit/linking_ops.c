/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linking_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:01:00 by vpaladii          #+#    #+#             */
/*   Updated: 2017/11/10 12:01:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetrominos.h"

void			link_new_node(t_node *col_node, t_node *row_node,
								t_node *new_node, t_node *tetra_node)
{
	t_node *col_el;

	col_el = col_node;
	while (col_el->down != col_node)
		col_el = col_el->down;
	row_node->right = new_node;
	col_el->down = new_node;
	new_node->up = col_el;
	new_node->down = col_node;
	new_node->left = row_node;
	new_node->right = tetra_node;
}

void			deattach_node(t_node *node)
{
	node->left->right = node->right;
	node->right->left = node->left;
	node->up->down = node->down;
	node->down->up = node->up;
}

void			attach_node(t_node *node)
{
	node->left->right = node;
	node->right->left = node;
	node->up->down = node;
	node->down->up = node;
}

void			deattach_elems(t_node **lst)
{
	int idx;

	idx = 0;
	while (lst[idx])
	{
		deattach_node(lst[idx]);
		idx++;
	}
}

void			attach_elems(t_node **lst)
{
	int idx;

	idx = 0;
	while (lst[idx])
	{
		attach_node(lst[idx]);
		idx++;
	}
}
