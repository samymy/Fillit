/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:41:00 by vpaladii          #+#    #+#             */
/*   Updated: 2017/11/10 12:41:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "field_ops.h"
#include "fillit.h"

char	**create_field(int field_size)
{
	char	**field;
	int		ind;

	if (!(field = (char**)malloc(sizeof(char*) * (field_size + 1))))
		return (NULL);
	ind = 0;
	while (ind < field_size)
	{
		field[ind] = (char*)malloc(sizeof(char) * (field_size + 1));
		ft_memset(field[ind], '.', field_size);
		field[ind][field_size] = '\0';
		ind++;
	}
	field[field_size] = NULL;
	return (field);
}

int		place_tetra(int tetra, char **field, t_point *point, char symb)
{
	int		ind;
	int		i;
	int		j;

	ind = 0;
	while (ind < 4)
	{
		i = g_tetras[tetra][ind].row + point->row;
		j = g_tetras[tetra][ind].col + point->col;
		field[i][j] = symb;
		ind++;
	}
	return (1);
}

void	unplace_tetra(int tetra, char **field, t_point *point)
{
	int		ind;
	int		i;
	int		j;

	ind = 0;
	while (ind < 4)
	{
		i = g_tetras[tetra][ind].row + point->row;
		j = g_tetras[tetra][ind].col + point->col;
		field[i][j] = '.';
		ind++;
	}
}
