/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:21:49 by jiwahn            #+#    #+#             */
/*   Updated: 2022/07/18 09:23:12 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	const size_t	length = ft_strlen(src);

	ft_memcpy(dst, src, length + 1);
	return (dst);
}
