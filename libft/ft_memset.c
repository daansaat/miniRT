/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaat <dsaat@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/08 12:18:08 by dsaat         #+#    #+#                 */
/*   Updated: 2021/11/08 13:20:05 by dsaat         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			index;
	unsigned char	*str;

	index = 0;
	str = (unsigned char *)b;
	while (index < len)
	{
		str[index] = c;
		index++;
	}
	return (b);
}
