/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:00:40 by vpaladii          #+#    #+#             */
/*   Updated: 2017/11/09 20:00:40 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetrominos.h"
#include "fillit.h"
#include "valid.h"
#include "others.h"

char			**get_arr(char *str)
{
	char	**arr;
	size_t	i;
	size_t	j;

	if (!str)
		return (NULL);
	if (!(arr = malloc_arr()))
		return (NULL);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
			arr[i][j++] = *str++;
		arr[i][j] = '\0';
		str++;
		i++;
	}
	return (arr);
}

t_point			get_offset(char **arr)
{
	int			i;
	int			j;
	t_point		offset;

	offset.row = -1;
	offset.col = -1;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (arr[i][j] == '#')
			{
				offset.row = i;
				offset.col = j;
				return (offset);
			}
			j++;
		}
		i++;
	}
	return (offset);
}

static int		find_tetra(t_point points[5])
{
	int			i;
	int			j;

	i = 0;
	while (i < 19)
	{
		j = 0;
		while (j < 4)
		{
			if (g_tetras[i][j].row != points[j].row ||
				g_tetras[i][j].col != points[j].col)
				break ;
			j++;
		}
		if (j == 4)
			return (i);
		i++;
	}
	return (-1);
}

int				get_tetra_code(char *tetra)
{
	char		**arr;
	t_point		points[5];
	int			i;
	int			j;
	int			k;

	if (!is_valid_tetra(tetra) || !(arr = get_arr(tetra)))
		return (-1);
	points[4] = get_offset(arr);
	i = -1;
	k = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			if (arr[i][j] == '#')
			{
				points[k].row = i - points[4].row;
				points[k].col = j - points[4].col;
				k++;
			}
	}
	free_arr(arr, i);
	return (find_tetra(points));
}

int				*get_tetras(int fd)
{
	char	buff[22];
	int		arr[27];
	int		*tetras;
	int		idx;
	int		rb;

	idx = 0;
	while ((rb = read(fd, buff, 21)) > 0)
	{
		if (buff[rb - 1] != '\n' && rb == 21)
			return (NULL);
		buff[rb] = '\0';
		if ((arr[idx++] = get_tetra_code(buff)) == -1)
			return (NULL);
	}
	if (ft_strcmp(buff, "") == 0 || buff[20] == '\n' || idx > 26)
		return (NULL);
	arr[idx] = -2;
	tetras = malloc(sizeof(int) * (idx + 1));
	ft_memcpy(tetras, arr, sizeof(int) * (idx + 1));
	return (tetras);
}
