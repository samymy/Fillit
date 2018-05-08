/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetra_arr_ops.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:52:00 by vpaladii          #+#    #+#             */
/*   Updated: 2017/11/10 12:52:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRA_ARR_OPS_H
# define TETRA_ARR_OPS_H

# include <unistd.h>

void	copy_tetras(int *tetras, int *tetras_copy);
int		no_tetras_left(int *tetras);
int		find_square_size(int *tetras);
void	remove_tetra(int *tetras, int tetra);

#endif
