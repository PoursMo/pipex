/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:21:34 by aloubry           #+#    #+#             */
/*   Updated: 2024/10/03 11:25:27 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	slen;

	slen = ft_strlen(s);
	dup = malloc(sizeof(char) * (slen + 1));
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s, slen + 1);
	return (dup);
}
