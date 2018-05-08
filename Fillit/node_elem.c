/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_elem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:18:00 by vpaladii          #+#    #+#             */
/*   Updated: 2017/11/10 12:18:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_elem.h"

t_node	*create_new_matrix_node(int row, int col, int tetra)
{
	t_node *new_node;

	new_node = malloc(sizeof(t_node));
	new_node->point.row = row;
	new_node->point.col = col;
	new_node->tetra = tetra;
	return (new_node);
}
