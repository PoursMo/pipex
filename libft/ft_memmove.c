/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:21:24 by aloubry           #+#    #+#             */
/*   Updated: 2024/10/03 11:24:08 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*cdest;
	const char	*csrc;

	if (!dest && !src)
		return (NULL);
	cdest = (char *)dest;
	csrc = (const char *)src;
	if (cdest > csrc && csrc + n > cdest)
		while (n--)
			cdest[n] = csrc[n];
	else
		while (n--)
			*cdest++ = *csrc++;
	return (dest);
}
