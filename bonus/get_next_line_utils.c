/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:50:04 by aloubry           #+#    #+#             */
/*   Updated: 2024/10/07 12:58:55 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	l;

	i = 0;
	while (i < size && dst[i])
		i++;
	if (i < size)
		l = i + ft_strlen(src);
	else
		return (size + ft_strlen(src));
	j = 0;
	while (i + 1 < size && src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (l);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*cs;

	cs = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (cs[i] == (unsigned char)c)
			return ((void *)cs + i);
		i++;
	}
	return (NULL);
}

static void	*ft_memset(void *s, int c, size_t n)
{
	char	*cs;

	cs = (char *)s;
	while (n--)
		*cs++ = c;
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*new;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	new = malloc(size * nmemb);
	if (!new)
		return (NULL);
	ft_memset(new, 0, nmemb * size);
	return (new);
}
