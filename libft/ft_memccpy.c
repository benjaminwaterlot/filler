/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaterlo <bwaterlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:18:05 by bwaterlo          #+#    #+#             */
/*   Updated: 2018/11/09 10:50:27 by bwaterlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*dest_string;
	unsigned char const	*src_string;

	dest_string = dest;
	src_string = src;
	i = 0;
	while (i < n)
	{
		dest_string[i] = src_string[i];
		if (dest_string[i] == (unsigned char)c)
			return ((void *)&dest_string[i + 1]);
		i++;
	}
	return (NULL);
}
