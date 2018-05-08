/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_ops.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:41:00 by vpaladii          #+#    #+#             */
/*   Updated: 2017/11/10 12:41:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIELD_OPS_H
# define FIELD_OPS_H

# include "fillit.h"

char	**create_field(int field_size);
int		place_tetra(int tetra, char **field, t_point *point, char symb);
void	unplace_tetra(int tetra, char **field, t_point *point);

#endif
