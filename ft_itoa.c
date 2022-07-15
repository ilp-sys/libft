/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 21:24:49 by jiwahn            #+#    #+#             */
/*   Updated: 2022/07/12 22:15:11 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	get_digit_byte(long long n)
{
	int	digit;

	digit = 1;
	while (n / 10)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

static void	get_digits(char *result, long long tmp, int len)
{
	if (len == 0)
		return ;
	result[--len] = tmp % 10 + '0';
	if (tmp == 0)
		return ;
	get_digits(result, tmp / 10, len);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*result;
	long long	tmp;

	tmp = n;
	len = get_digit_byte(tmp);
	if (n < 0)
	{
		len++;
		tmp *= -1;
	}
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	get_digits(result, tmp, len);
	if (n < 0)
		result[0] = '-';
	result[len] = '\0';
	return (result);
}
