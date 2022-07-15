/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:00:26 by jiwahn            #+#    #+#             */
/*   Updated: 2022/07/11 15:16:57 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dstptr;

	if (!dst && !src)
		return (NULL);
	dstptr = dst;
	while (n-- > 0)
		*(char *)dst++ = *(char *)src++;
	return (dstptr);
}
