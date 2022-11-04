#include "libft.h"
#define BUFFER_SIZE 1000

void	ft_free(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

bool	ft_read(char **str, int fd, char *buf)
{
	int	result;
	char	*temp;

	result = 1;
	if (str[fd] == NULL)
		return (false);
	while (ft_strchr(str[fd], '\n') == NULL && result)
	{
		result = read(fd, buf, BUFFER_SIZE);
		if ((!ft_strlen(str[fd]) && result == 0) || result == -1)
		{
			ft_free(&str[fd]);
			return (false);
		}
		else if (result == 0)
			break ;
		buf[result] = '\0';
		temp = str[fd];
		str[fd] = ft_strjoin(str[fd], buf);
		ft_free(&temp);
	}
	return (true);
}

char	*get_line(char **str, int fd)
{
	char	*line;
	char	*tmp;
	int		i;

	tmp = str[fd];
	if (ft_strchr(tmp, '\n') == NULL)
	{
		line = ft_strdup(tmp);
		str[fd] = NULL;
	}
	else
	{
		i = 0;
		while (tmp[i] != '\n')
			i++;
		line = (char *)malloc(i + 2);
		if (line == NULL)
			return (NULL);
		if (ft_strlcpy(line, tmp, i + 2) == 0)
			return (NULL);
		str[fd] = ft_strdup((char *)(tmp + i + 1));
	}
	ft_free(&tmp);
	return (line);
}

char	*ft_get_next_line(int fd)
{
	static char	*str[1024];
	char		*buf;
	char		*line;

	if (fd < 0 || fd > 1024)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	if (str[fd] == NULL)
		str[fd] = ft_strdup("");
	if (ft_read(str, fd, buf) == false)
	{
		ft_free(&buf);
		return (NULL);
	}
	line = get_line(str, fd);
	if (line == NULL)
	{
		ft_free(&str[fd]);
		return (NULL);
	}
	ft_free(&buf);
	return (line);
}