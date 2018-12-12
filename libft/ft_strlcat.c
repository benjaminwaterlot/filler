/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaterlo <bwaterlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 17:01:35 by bwaterlo          #+#    #+#             */
/*   Updated: 2018/11/12 12:10:57 by bwaterlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	res;
	size_t	dest_length;
	int		counter;

	dest_length = ft_strlen(dest);
	if (size == 0)
		return (ft_strlen(src));
	res = (size <= dest_length) ? size : dest_length;
	res += ft_strlen(src);
	counter = 0;
	while (src[counter] && (dest_length + counter < size - 1))
	{
		dest[dest_length + counter] = src[counter];
		counter++;
	}
	dest[dest_length + counter] = '\0';
	return (res);
}
