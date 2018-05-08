/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_elem.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:18:00 by vpaladii          #+#    #+#             */
/*   Updated: 2017/11/10 12:18:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_ELEM_H
# define NODE_ELEM_H

# include <stdlib.h>
# include "tetrominos.h"

t_node	*create_new_matrix_node(int row, int col, int tetra);

#endif
