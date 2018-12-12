/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaterlo <bwaterlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 13:58:00 by bwaterlo          #+#    #+#             */
/*   Updated: 2018/11/08 15:59:36 by bwaterlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *source, const char *pattern)
{
	int		i;

	i = 0;
	if (!*source && !*pattern)
		return ((char *)source);
	while (source[i])
	{
		if (ft_memcmp(&source[i], pattern, ft_strlen(pattern)) == 0)
			return ((char *)&source[i]);
		i++;
	}
	return (NULL);
}
