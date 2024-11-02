/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:17:46 by aloubry           #+#    #+#             */
/*   Updated: 2024/10/03 13:55:59 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup(const char *s, size_t n)
{
	char	*dup;
	size_t	size;

	if (!s)
		return (NULL);
	if (n > ft_strlen(s))
		size = ft_strlen(s);
	else
		size = n;
	dup = malloc(sizeof(char) * (size + 1));
	if (!dup)
		return (NULL);
	ft_memcpy(dup, s, size);
	dup[size] = '\0';
	return (dup);
}

static int	count_strs(const char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str && *str != c)
		{
			count++;
			while (*str && *str != c)
				str++;
		}
	}
	return (count);
}

char	**free_split(char **split, int count)
{
	while (count--)
		free(split[count]);
	free(split);
	return (NULL);
}

char	**ft_split(const char *str, char c)
{
	char	**split;
	int		i;
	int		size;

	split = malloc(sizeof(char *) * (count_strs(str, c) + 1));
	if (!split)
		return (NULL);
	i = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str && *str != c)
		{
			size = 0;
			while (*(str + size) && *(str + size) != c)
				size++;
			split[i] = ft_strndup(str, size);
			if (!split[i])
				return (free_split(split, i));
			i++;
			str += size;
		}
	}
	return (split[i] = NULL, split);
}
