/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:40:43 by jiwahn            #+#    #+#             */
/*   Updated: 2022/07/13 00:31:55 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_charset(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int			start;
	int			end;
	char const	*tmp;

	tmp = s1;
	start = 0;
	end = ft_strlen(s1);
	while (*s1)
	{
		if (!in_charset(*s1++, set))
			break ;
		start++;
	}
	while (*s1)
		s1++;
	while (end >= start)
	{
		if (!in_charset(*(--s1), set))
			break ;
		end--;
	}
	return (ft_substr(tmp, start, end - start));
}
