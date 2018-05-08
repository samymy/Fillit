/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetra_arr_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:40:00 by vpaladii          #+#    #+#             */
/*   Updated: 2017/11/09 19:40:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetra_arr_ops.h"

void				copy_tetras(int *tetras, int *tetras_copy)
{
	while (*tetras != -2)
		*tetras_copy++ = *tetras++;
	*tetras_copy = -2;
}

int					no_tetras_left(int *tetras)
{
	while (*tetras != -2)
		if (*tetras++ != -1)
			return (0);
	return (1);
}

int					find_square_size(int *tetras)
{
	int blocks;
	int square_size;

	blocks = 0;
	square_size = 1;
	while (*tetras++ != -2)
		blocks += 4;
	while (square_size * square_size < blocks)
		square_size++;
	return (square_size);
}

void				remove_tetra(int *tetras, int tetra)
{
	while (*tetras != -2)
	{
		if (*tetras == tetra)
		{
			*tetras = -1;
			return ;
		}
		tetras++;
	}
}
