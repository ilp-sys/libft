/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 21:08:23 by jiwahn            #+#    #+#             */
/*   Updated: 2022/07/12 20:46:33 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	get_word_count(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == '\0' || *(s + 1) == c))
			count++;
		s++;
	}
	return (count);
}

static char	**free_all(char **result, int cnt)
{
	int	i;

	i = 0;
	while (i < cnt)
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

static char const	*trimming(char const *s, char c)
{
	while (*s == c && c != '\0')
		s++;
	return (s);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**result;

	if (!s)
		return (NULL);
	s = trimming(s, c);
	result = (char **)malloc(sizeof(char *) * (get_word_count(s, c) + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (*s)
	{
		j = 0;
		while (s[j] != c && s[j] != '\0')
			j++;
		result[i] = (char *)malloc(sizeof(char) * (j + 1));
		if (!result[i])
			return (free_all(result, i + 1));
		ft_strlcpy(result[i++], s, j + 1);
		s += j;
		s = trimming(s, c);
	}
	result[i] = NULL;
	return (result);
}
