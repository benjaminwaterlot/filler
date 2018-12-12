/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaterlo <bwaterlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:18:05 by bwaterlo          #+#    #+#             */
/*   Updated: 2018/11/07 13:23:18 by bwaterlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dest_string;
	char const	*src_string;

	dest_string = dest;
	src_string = src;
	i = 0;
	while (i < n)
	{
		dest_string[i] = src_string[i];
		i++;
	}
	return (dest);
}
