/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fuck_moulinette.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 17:51:00 by vpaladii          #+#    #+#             */
/*   Updated: 2017/11/18 17:51:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptrcpy;

	ptrcpy = (unsigned char*)b;
	while (len--)
		*ptrcpy++ = (unsigned char)c;
	return (b);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*srccpy;
	unsigned char	*dstcpy;

	srccpy = (unsigned char*)src;
	dstcpy = (unsigned char*)dst;
	while (n--)
		*dstcpy++ = *srccpy++;
	return (dst);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char const *s)
{
	if (s)
		while (*s != '\0')
			ft_putchar(*s++);
}

void	ft_putstrarr(char **words, char del)
{
	if (words)
	{
		while (*words)
		{
			ft_putstr(*words++);
			if (*(words))
				ft_putchar(del);
		}
	}
}
