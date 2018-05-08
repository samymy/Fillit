/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gather_elems.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:22:00 by vpaladii          #+#    #+#             */
/*   Updated: 2017/11/10 13:22:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GATHER_ELEMS_H
# define GATHER_ELEMS_H

# include "tetrominos.h"
# include "additional.h"
# include <stdlib.h>

void				gather_row(t_node **lst, t_node *matrix_head,
							int tetra, int *tetras_copy);
void				gather_elems(t_node **lst, t_node *matrix_head,
							char **field);

#endif
