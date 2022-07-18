/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:57:28 by jiwahn            #+#    #+#             */
/*   Updated: 2022/07/11 12:21:45 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

static void	print_reverse(unsigned char nbr[10], int index, int fd)
{
	while (index >= 0)
	{
		write(fd, &nbr[index], 1);
		index--;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int				i;
	long long int	quotient;
	unsigned char	nbr[10];

	i = 0;
	quotient = n;
	if (quotient < 0)
	{
		write(fd, "-", 1);
		quotient *= -1;
	}
	while (1)
	{
		nbr[i] = quotient % 10 + '0';
		quotient = quotient / 10;
		if (quotient == 0)
			break ;
		i++;
	}
	print_reverse(nbr, i, fd);
}
