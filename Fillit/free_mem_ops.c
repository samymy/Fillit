/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem_ops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:38:00 by vpaladii          #+#    #+#             */
/*   Updated: 2017/11/10 12:38:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_mem_ops.h"
#include <stdlib.h>

void		free_field(char **field)
{
	int	ind;

	ind = 0;
	while (field[ind])
		free(field[ind++]);
	free(field);
	*field = NULL;
}

void		clear_nodelst(t_node **lst)
{
	int idx;

	idx = 0;
	while (lst[idx])
	{
		lst[idx] = NULL;
		idx++;
	}
}

static void	free_row(t_node *row)
{
	t_node	*head;
	t_node	*next;

	head = row;
	row = row->right;
	while (row != head)
	{
		next = row->right;
		free(row);
		row = next;
	}
}

void		free_matrix(t_node *matrix)
{
	t_node	*head;
	t_node	*next;

	head = matrix;
	matrix = matrix->down;
	while (matrix != head)
	{
		next = matrix->down;
		free_row(matrix);
		matrix = next;
	}
	free_row(matrix);
	matrix = matrix->down;
	while (matrix != head)
	{
		next = matrix->down;
		free(matrix);
		matrix = next;
	}
	free(matrix);
}
