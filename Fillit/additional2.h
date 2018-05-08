/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional2.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:26:00 by vpaladii          #+#    #+#             */
/*   Updated: 2017/11/13 13:26:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADDITIONAL2_H
# define ADDITIONAL2_H

# include "solve_alg.h"

typedef struct	s_sol
{
	char		**field;
	int			*tetras;
	t_node		*matrix;
	t_node		**temp_lst;
}				t_sol;

t_node			**init_static_list(void);
void			copy_solution(t_sol *solution, t_sol *sol_copy,
							int *tetras_copy, int idx);
int				null_idx(t_node **temp_lst);

#endif
