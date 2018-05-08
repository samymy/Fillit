/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_alg.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:17:00 by vpaladii          #+#    #+#             */
/*   Updated: 2017/11/05 12:17:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_ALG_H
# define SOLVE_ALG_H

# include "fillit.h"
# include "tetrominos.h"
# include "linking_ops.h"
# include "field_ops.h"
# include "tetra_arr_ops.h"
# include "free_mem_ops.h"
# include "additional.h"
# include "additional2.h"
# include "gather_elems.h"

int		rec_solve(t_sol *solution, int idx);
t_node	*init_matrix(int *tetras, int square_size);

#endif
