/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linking_ops.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:03:00 by vpaladii          #+#    #+#             */
/*   Updated: 2017/11/10 12:03:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKING_OPS_H
# define LINKING_OPS_H

# include "tetrominos.h"

void				link_new_node(t_node *col_node, t_node *row_node,
								t_node *new_node, t_node *tetra_node);
void				deattach_node(t_node *node);
void				attach_node(t_node *node);
void				deattach_elems(t_node **lst);
void				attach_elems(t_node **lst);

#endif
