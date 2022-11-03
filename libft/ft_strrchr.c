/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaat <dsaat@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/08 12:19:30 by dsaat         #+#    #+#                 */
/*   Updated: 2021/11/08 12:19:31 by dsaat         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	index;

	index = ft_strlen((char *)s);
	while (index >= 0)
	{
		if (*(s + index) == (char)c)
			return ((char *)s + index);
		index--;
	}
	return (NULL);
}
