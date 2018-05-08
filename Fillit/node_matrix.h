/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_matrix.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:24:09 by vpaladii          #+#    #+#             */
/*   Updated: 2017/11/10 12:24:11 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_MATRIX_H
# define NODE_MATRIX_H

# include "tetrominos.h"
# include "linking_ops.h"

void			init_column_row(t_node *header, int square_size);
void			add_tetra_row(t_node *header, int tetra, int square_size);
void			add_tetra_row(t_node *header, int tetra, int square_size);

#endif
