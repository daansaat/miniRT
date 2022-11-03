/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaat <dsaat@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/08 12:19:03 by dsaat         #+#    #+#                 */
/*   Updated: 2021/11/08 13:32:02 by dsaat         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_d;
	size_t	len_s;
	size_t	offset;
	size_t	index;

	len_d = ft_strlen(dst);
	len_s = ft_strlen(src);
	offset = len_d;
	index = 0;
	if (dstsize == 0)
		return (len_s);
	if (dstsize < len_d)
		return (dstsize + len_s);
	if (dstsize > 0)
	{
		while ((src[index] != '\0') && (offset < dstsize - 1))
		{
			dst[offset] = src[index];
			offset++;
			index++;
		}
		dst[offset] = '\0';
	}
	return (len_d + len_s);
}
