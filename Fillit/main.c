/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 13:22:00 by vpaladii          #+#    #+#             */
/*   Updated: 2017/11/11 14:22:28 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "solve_alg.h"
#include "node_matrix.h"

int		main(int argc, char **argv)
{
	char	**solution;
	int		*tetras;
	int		fd;

	if (argc != 2)
		ft_putstr("usage: ./fillit filename\n");
	else
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
		{
			ft_putstr("error\n");
			return (0);
		}
		if (!(tetras = get_tetras(fd)))
		{
			ft_putstr("error\n");
			return (0);
		}
		solution = solve(tetras);
		ft_putstrarr(solution, '\n');
		ft_putchar('\n');
	}
	return (0);
}
