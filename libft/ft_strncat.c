/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaterlo <bwaterlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 13:22:39 by bwaterlo          #+#    #+#             */
/*   Updated: 2018/11/08 11:13:13 by bwaterlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t nb)
{
	size_t	dest_length;
	size_t	counter;

	dest_length = 0;
	while (dest[dest_length])
		++dest_length;
	counter = 0;
	while (src[counter] && counter < nb)
	{
		dest[dest_length + counter] = src[counter];
		counter++;
	}
	dest[dest_length + counter] = '\0';
	return (dest);
}
