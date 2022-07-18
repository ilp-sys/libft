/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 21:48:31 by jiwahn            #+#    #+#             */
/*   Updated: 2022/07/12 22:16:48 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*needle)
		return ((char *)haystack);
	j = 0;
	while (*haystack && j < len)
	{
		i = 0;
		if (*haystack == needle[i])
		{
			while (needle[i] && *(haystack + i) == needle[i] && (i + j) < len)
				i++;
			if (needle[i] == '\0')
				return ((char *)haystack);
		}
		haystack++;
		j++;
	}
	return (NULL);
}
