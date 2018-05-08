/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:37:00 by vpaladii          #+#    #+#             */
/*   Updated: 2017/11/10 12:37:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetrominos.h"
#include <stdio.h>

int		find_tetra(int *arr, int elem)
{
	int idx;

	idx = 0;
	while (arr[idx] != -2)
	{
		if (arr[idx] == elem)
			return (idx);
		idx++;
	}
	return (-1);
}

int		first_tetra(int *tetras)
{
	int tetra_idx;

	tetra_idx = 0;
	while (tetras[tetra_idx] == -1)
		tetra_idx++;
	return (tetra_idx);
}

int		is_tetra_in_col(int tetra, t_node *col_node, t_node *head)
{
	t_node *row_node;
	t_node *col_node2;

	row_node = head->down;
	while (row_node != head && row_node->tetra != tetra)
		row_node = row_node->down;
	if (row_node == head)
		return (0);
	col_node2 = row_node->right;
	while (col_node2 != row_node)
	{
		if (col_node->point.row == col_node2->point.row &&
				col_node->point.col == col_node2->point.col)
			return (1);
		col_node2 = col_node2->right;
	}
	return (0);
}

int		is_placeable(int tetra, char **field, t_point *point, int square_size)
{
	int		point_idx;
	t_point	*point_ptr;
	int		row;
	int		col;

	point_idx = 0;
	point_ptr = g_tetras[tetra];
	while (point_idx < 4)
	{
		row = point_ptr[point_idx].row + point->row;
		col = point_ptr[point_idx].col + point->col;
		if (row >= square_size ||
			col >= square_size ||
			col < 0 ||
			field[row][col] != '.')
			return (0);
		point_idx++;
	}
	return (1);
}

int		matrix_not_empty(t_node *matrix)
{
	t_node *node;

	node = matrix->down;
	while (node != matrix)
	{
		if (node->right != node)
			return (1);
		node = node->down;
	}
	return (0);
}
