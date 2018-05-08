/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdubinki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 10:28:15 by vdubinki          #+#    #+#             */
/*   Updated: 2017/11/13 10:28:17 by vdubinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	free_arr(char **arr, size_t arr_size)
{
	size_t	ind;

	ind = 0;
	while (ind < arr_size)
		free(arr[ind++]);
	free(arr);
}

char	**malloc_arr(void)
{
	char	**arr;
	size_t	ind;

	arr = (char	**)malloc(sizeof(char *) * 4);
	if (!arr)
		return (NULL);
	ind = 0;
	while (ind < 4)
	{
		arr[ind] = (char *)malloc(sizeof(char) * 5);
		if (!arr[ind])
		{
			free_arr(arr, ind);
			return (NULL);
		}
		ind++;
	}
	return (arr);
}
