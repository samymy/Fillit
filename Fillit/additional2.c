/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:27:00 by vpaladii          #+#    #+#             */
/*   Updated: 2017/11/13 13:27:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solve_alg.h"

t_node	**init_static_list(void)
{
	t_node	**res;
	int		size;

	size = 144 * 19;
	res = malloc(sizeof(t_node*) * (size));
	ft_memset(res, 0, sizeof(t_node*) * size);
	return (res);
}

void	copy_solution(t_sol *solution, t_sol *sol_copy, int *tetras_copy,
					int idx)
{
	copy_tetras(solution->tetras, tetras_copy);
	sol_copy->tetras = tetras_copy;
	sol_copy->field = solution->field;
	sol_copy->temp_lst = solution->temp_lst + idx;
	sol_copy->matrix = solution->matrix;
}

int		null_idx(t_node **temp_lst)
{
	int idx;

	idx = 0;
	while (temp_lst[idx] != NULL)
		idx++;
	return (idx);
}
