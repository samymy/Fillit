/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdubinki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 14:00:29 by vdubinki          #+#    #+#             */
/*   Updated: 2017/11/11 14:00:31 by vdubinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_1(char *tetra)
{
	int		index;

	index = 4;
	while (index < 21)
	{
		if (tetra[index] != '\n')
			return (0);
		index += 5;
	}
	return (1);
}

int		check_2(char *tetra)
{
	int		index;
	int		count;
	int		break_count;

	index = -1;
	count = 0;
	break_count = 0;
	while (++index < 20)
	{
		if (break_count == 4)
		{
			break_count = 0;
			continue ;
		}
		if (tetra[index] != '.' && tetra[index] != '#')
			return (0);
		if (tetra[index] == '#')
			count++;
		if (count > 4)
			return (0);
		break_count++;
	}
	return (1);
}

int		is_valid_tetra(char *tetra)
{
	if (!check_1(tetra))
		return (0);
	if (!check_2(tetra))
		return (0);
	return (1);
}
