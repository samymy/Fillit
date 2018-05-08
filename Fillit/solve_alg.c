/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_alg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:08:00 by vpaladii          #+#    #+#             */
/*   Updated: 2017/11/05 12:08:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solve_alg.h"

char	**solve(int *tetras)
{
	int				square_size;
	static	t_node	**temp_lst = NULL;
	t_sol			solution;

	if (temp_lst == NULL)
		temp_lst = init_static_list();
	solution.temp_lst = temp_lst;
	solution.tetras = tetras;
	square_size = find_square_size(tetras);
	while (1)
	{
		solution.field = create_field(square_size);
		solution.matrix = init_matrix(tetras, square_size);
		if (rec_solve(&solution, 0))
			break ;
		square_size++;
		free_field(solution.field);
		free_matrix(solution.matrix);
		clear_nodelst(solution.temp_lst);
	}
	free_matrix(solution.matrix);
	free(*temp_lst);
	return (solution.field);
}

void	prepare(t_sol *sol, int tetra, t_node *col_node)
{
	place_tetra(tetra, sol->field, &(col_node->point),
				find_tetra(sol->tetras, tetra) + 'A');
	remove_tetra(sol->tetras, tetra);
	gather_row(sol->temp_lst, sol->matrix, tetra, sol->tetras);
	gather_elems(sol->temp_lst, sol->matrix, sol->field);
	deattach_elems(sol->temp_lst);
}

void	restore(t_sol *sol, int tetra, int *tetras, t_node *col_node)
{
	attach_elems(sol->temp_lst);
	unplace_tetra(tetra, sol->field, &(col_node->point));
	copy_tetras(tetras, sol->tetras);
	clear_nodelst(sol->temp_lst);
}

int		rec_call(t_sol *sol, int tetra, t_node *col_node, t_sol *solution)
{
	prepare(sol, tetra, col_node);
	if (rec_solve(sol, null_idx(sol->temp_lst)))
		return (1);
	restore(sol, tetra, solution->tetras, col_node);
	return (0);
}

int		rec_solve(t_sol *solution, int idx)
{
	t_node		*col_node;
	int			tetra;
	int			tetra_idx;
	int			tetras_copy[27];
	t_sol		sol;

	if (no_tetras_left(solution->tetras))
		return (1);
	copy_solution(solution, &sol, tetras_copy, idx);
	col_node = sol.matrix->right;
	tetra_idx = 0;
	while (sol.tetras[tetra_idx] != -2 && matrix_not_empty(sol.matrix))
	{
		while (sol.tetras[tetra_idx] == -1)
			tetra_idx++;
		tetra = sol.tetras[tetra_idx++];
		while (col_node != sol.matrix)
		{
			if (is_tetra_in_col(tetra, col_node, sol.matrix))
				if (rec_call(&sol, tetra, col_node, solution))
					return (1);
			col_node = col_node->right;
		}
	}
	return (0);
}
