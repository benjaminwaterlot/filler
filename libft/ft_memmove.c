/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaterlo <bwaterlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 10:52:14 by bwaterlo          #+#    #+#             */
/*   Updated: 2018/11/08 11:37:14 by bwaterlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int			i;
	char		*dest_str;
	const char	*src_str;

	dest_str = dest;
	src_str = src;
	if (dest > src)
	{
		i = n;
		while (--i >= 0)
			dest_str[i] = src_str[i];
	}
	else
	{
		i = -1;
		while (++i < (int)n)
			dest_str[i] = src_str[i];
	}
	return (dest);
}
