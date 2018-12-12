/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaterlo <bwaterlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 13:58:00 by bwaterlo          #+#    #+#             */
/*   Updated: 2018/11/12 13:47:05 by bwaterlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t size)
{
	size_t	small_length;

	if (!*small)
		return ((char *)big);
	small_length = ft_strlen(small);
	while (*big != '\0' && size-- >= small_length)
	{
		if (*big == *small && ft_memcmp(big, small, small_length) == 0)
			return ((char *)big);
		big++;
	}
	return (NULL);
}
