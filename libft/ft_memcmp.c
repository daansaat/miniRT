/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaat <dsaat@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/08 12:17:52 by dsaat         #+#    #+#                 */
/*   Updated: 2021/11/08 13:14:34 by dsaat         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	int				x;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	x = 0;
	while (n > 0)
	{
		if (p1[x] != p2[x])
			return (p1[x] - p2[x]);
		x++;
		n--;
	}
	return (0);
}
