/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 20:32:25 by jiwahn            #+#    #+#             */
/*   Updated: 2022/07/12 22:15:33 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *)s;
	while (i < n)
	{
		if (*p == (unsigned char)c)
			return (p);
		p++;
		i++;
	}
	return (NULL);
}
