/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:07:00 by vpaladii          #+#    #+#             */
/*   Updated: 2017/11/05 12:07:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H

# include <stdlib.h>
# include "libft.h"
# include <fcntl.h>
# include "tetrominos.h"

char	**solve(int *tetras);
int		*get_tetras(int fd);
void	print_matrix(t_node *header, int square_size);

#endif
