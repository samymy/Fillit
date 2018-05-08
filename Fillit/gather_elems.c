/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gather_elems.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:22:00 by vpaladii          #+#    #+#             */
/*   Updated: 2017/11/10 13:22:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gather_elems.h"
#include "tetra_arr_ops.h"
#include "fillit.h"

void				gather_row(t_node **lst, t_node *matrix_head,
							int tetra, int *tetras_copy)
{
	int			idx;
	t_node		*row_node;

	if (find_tetra(tetras_copy, tetra) == -1)
	{
		idx = 0;
		while (lst[idx] != NULL)
			idx++;
		row_node = matrix_head->down;
		while (row_node != matrix_head)
		{
			if (row_node->tetra == tetra)
			{
				lst[idx++] = row_node;
				return ;
			}
			row_node = row_node->down;
		}
	}
}

void				gather_elems(t_node **lst, t_node *matrix_head,
							char **field)
{
	t_node		*row_node;
	t_node		*node;
	int			idx;
	int			square_size;

	square_size = ft_strlen(field[0]);
	idx = 0;
	while (lst[idx] != NULL)
		idx++;
	row_node = matrix_head->down;
	while (row_node != matrix_head)
	{
		node = row_node->right;
		while (node != row_node)
		{
			if (!(is_placeable(node->tetra, field,
							&(node->point), square_size)))
				lst[idx++] = node;
			node = node->right;
		}
		row_node = row_node->down;
	}
}
