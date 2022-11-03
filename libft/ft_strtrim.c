/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaat <dsaat@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/08 12:19:35 by dsaat         #+#    #+#                 */
/*   Updated: 2021/11/12 15:55:03 by dsaat         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		i;
	size_t		j;

	if (!s1)
		return (NULL);
	i = 0;
	j = ft_strlen((char *)s1);
	while (ft_strchr(set, s1[i]))
		i++;
	while (ft_strchr(set, s1[j - 1]))
		j--;
	return (ft_substr(s1, i, j - i));
}
