/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_matrix.c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:00:00 by vpaladii          #+#    #+#             */
/*   Updated: 2017/11/09 13:00:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_matrix.h"
#include "tetrominos.h"
#include "node_elem.h"
#include "linking_ops.h"
#include "additional.h"

static int	is_place(int tetra, int row, int col, int square_size)
{
	int		point_idx;
	t_point	*point_ptr;

	point_idx = 0;
	point_ptr = g_tetras[tetra];
	while (point_idx < 4)
	{
		if (point_ptr[point_idx].col + col >= square_size ||
			point_ptr[point_idx].row + row >= square_size ||
			point_ptr[point_idx].col + col < 0)
			return (0);
		point_idx++;
	}
	return (1);
}

void		init_column_row(t_node *header, int square_size)
{
	t_node	*left_node;
	t_node	*temp_node;
	int		i;

	left_node = header;
	i = 0;
	while (i <= square_size * square_size)
	{
		temp_node = create_new_matrix_node(i / square_size,
										i % square_size, -1);
		temp_node->up = temp_node;
		temp_node->down = temp_node;
		temp_node->left = left_node;
		left_node->right = temp_node;
		left_node = temp_node;
		i++;
	}
	temp_node->right = header;
	header->left = temp_node;
}

t_node		*make_row_node(t_node *header, int tetra)
{
	t_node *tetra_node;

	tetra_node = header;
	while (tetra_node->down != header)
		tetra_node = tetra_node->down;
	tetra_node->down = create_new_matrix_node(-1, -1, tetra);
	tetra_node->down->up = tetra_node;
	tetra_node->down->down = header;
	tetra_node = tetra_node->down;
	tetra_node->right = tetra_node;
	tetra_node->left = tetra_node;
	return (tetra_node);
}

void		add_tetra_row(t_node *header, int tetra, int square_size)
{
	int		square_num;
	t_node	*tetra_node;
	t_node	*row_node;
	t_node	*col_node;
	t_node	*new_node;

	tetra_node = make_row_node(header, tetra);
	col_node = header;
	square_num = 0;
	row_node = tetra_node;
	while (square_num < square_size * square_size)
	{
		col_node = col_node->right;
		if (is_place(tetra, col_node->point.row,
						col_node->point.col, square_size))
		{
			new_node = create_new_matrix_node(col_node->point.row,
									col_node->point.col, tetra);
			link_new_node(col_node, row_node, new_node, tetra_node);
			row_node = row_node->right;
		}
		square_num++;
	}
	tetra_node->left = row_node;
}

t_node		*init_matrix(int *tetras, int square_size)
{
	t_node	*header;
	t_node	*row_node;
	int		i;

	header = create_new_matrix_node(-1, -1, -1);
	header->up = header;
	header->down = header;
	init_column_row(header, square_size);
	i = 0;
	while (tetras[i] != -2)
	{
		row_node = header->down;
		while (row_node != header)
		{
			if (row_node->tetra == tetras[i])
				break ;
			row_node = row_node->down;
		}
		if (row_node == header)
			add_tetra_row(header, tetras[i], square_size);
		i++;
	}
	return (header);
}
