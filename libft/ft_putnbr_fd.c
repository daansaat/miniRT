/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaat <dsaat@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/08 12:18:32 by dsaat         #+#    #+#                 */
/*   Updated: 2021/11/08 12:18:33 by dsaat         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	digit;

	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		n = n * -1;
		write(fd, "-", 1);
	}
	if (n <= 9)
	{
		n = n + 48;
		write (fd, &n, 1);
		return ;
	}
	if (n > 9)
	{
		digit = n % 10 + 48;
		ft_putnbr_fd(n / 10, fd);
		write(fd, &digit, 1);
	}
}
