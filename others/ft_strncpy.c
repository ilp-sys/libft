/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:23:44 by jiwahn            #+#    #+#             */
/*   Updated: 2022/07/18 09:25:38 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strncpy(char *dst, const char *src, size_t maxlen)
{
	const size_t	srclen = strnlen(src, maxlen);

	if (srclen < maxlen)
	{
		ft_memcpy(dst, src, srclen);
		ft_memset(dst + srclen, 0, maxlen - srclen);
	}
	else
		ft_memcpy(dst, src, maxlen);
	return (dst);
}
