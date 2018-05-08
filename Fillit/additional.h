/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:58:00 by vpaladii          #+#    #+#             */
/*   Updated: 2017/11/10 12:58:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADDITIONAL_H
# define ADDITIONAL_H

# include "tetrominos.h"

void	print_matrix(t_node *header, int square_size);
int		is_tetra_in_col(int tetra, t_node *col_node, t_node *head);
int		find_tetra(int *arr, int elem);
int		is_placeable(int tetra, char **field, t_point *point, int square_size);
int		matrix_not_empty(t_node *matrix);

#endif
