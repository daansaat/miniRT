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

static int	ft_word_count(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static int	ft_word_size(const char *s, int i, char c)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i] != '\0')
	{
		size++;
		i++;
	}
	return (size);
}

static int	ft_skip(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	return (i);
}

static char	**ft_delete(char **s1, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free(s1[i]);
		i++;
	}
	free(s1);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**s1;
	int		word_count;
	int		word_size;
	int		index_s1;
	int		i;

	if (!s)
		return (NULL);
	word_count = ft_word_count(s, c);
	s1 = (char **)malloc(sizeof(s) * (word_count + 1));
	if (!s1)
		return (NULL);
	index_s1 = 0;
	while (index_s1 < word_count)
	{
		i = ft_skip(s, c);
		word_size = ft_word_size(s, i, c);
		s1[index_s1] = ft_substr(s + i, 0, word_size);
		if (!s1[index_s1])
			return (ft_delete(s1, index_s1));
		index_s1++;
		s = s + i + word_size;
	}
	s1[index_s1] = NULL;
	return (s1);
}