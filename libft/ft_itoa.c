/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:17:07 by aloubry           #+#    #+#             */
/*   Updated: 2024/10/03 12:02:10 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(int num)
{
	int	size;

	if (num <= 0)
		size = 1;
	else
		size = 0;
	while (num)
	{
		size++;
		num /= 10;
	}
	return (size);
}

static char	*int_min_str(void)
{
	char	*int_min_str;

	int_min_str = ft_calloc(sizeof(char), 12);
	if (!int_min_str)
		return (NULL);
	ft_strlcpy(int_min_str, "-2147483648", 12);
	return (int_min_str);
}

static char	*zero_str(void)
{
	char	*zero_str;

	zero_str = ft_calloc(sizeof(char), 2);
	if (!zero_str)
		return (NULL);
	ft_strlcpy(zero_str, "0", 2);
	return (zero_str);
}

char	*ft_itoa(int num)
{
	char	*conv;
	int		size;
	int		i;

	if (num == 0)
		return (zero_str());
	if (num == -2147483648)
		return (int_min_str());
	size = get_size(num);
	conv = ft_calloc(sizeof(char), size + 1);
	if (!conv)
		return (NULL);
	if (num < 0)
	{
		num = -num;
		conv[0] = '-';
	}
	i = size - 1;
	while (num > 0)
	{
		conv[i--] = num % 10 + '0';
		num /= 10;
	}
	conv[size] = '\0';
	return (conv);
}
