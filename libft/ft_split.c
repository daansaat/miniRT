/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaat <dsaat@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/08 12:18:39 by dsaat         #+#    #+#                 */
/*   Updated: 2021/11/11 12:08:37 by dsaat         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const*s, char c)
{
	int	count;

	count = 0;
	if (!s)
		return (0);
	while (*s)
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s != c && *s != '\0')
			count++;
		while (*s != c && *s != '\0')
			s++;
	}
	return (count);
}

static void	ft_get_str(char **str, int *i, char c)
{
	*str = *str + *i;
	*i = 0;
	while (**str && **str == c)
		(*str)++;
	while (*(*str + *i))
	{
		if (*(*str + *i) == c)
			break ;
		(*i)++;
	}
}

static void	*ft_delete(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	char	*str;
	int		nb_strs;
	int		i;
	int		x;

	nb_strs = ft_count(s, c);
	ptr = ft_calloc(sizeof(char *), (nb_strs + 1));
	if (!(ptr))
		return (NULL);
	i = 0;
	x = 0;
	str = (char *)s;
	while (x < nb_strs)
	{
		ft_get_str(&str, &i, c);
		ptr[x] = ft_substr(str, 0, i);
		if (!(ptr[x]))
			return (ft_delete(ptr));
		x++;
	}
	return (ptr);
}
