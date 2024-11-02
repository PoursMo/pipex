/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:21:44 by aloubry           #+#    #+#             */
/*   Updated: 2024/10/03 11:28:36 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *substr, size_t n)
{
	size_t	substrlen;

	substrlen = ft_strlen(substr);
	if (!*substr)
		return ((char *)str);
	while (*str && n > 0)
	{
		if (n < substrlen)
			return (NULL);
		if (!ft_memcmp(str++, substr, substrlen))
			return ((char *)str - 1);
		n--;
	}
	return (NULL);
}
