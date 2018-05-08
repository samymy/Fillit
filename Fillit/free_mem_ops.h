/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem_ops.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:38:00 by vpaladii          #+#    #+#             */
/*   Updated: 2017/11/10 12:38:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_MEM_OPS_H
# define FREE_MEM_OPS_H

# include "tetrominos.h"

void	free_field(char **field);
void	clear_nodelst(t_node **lst);
void	free_matrix(t_node *matrix);

#endif
