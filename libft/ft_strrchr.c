/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaterlo <bwaterlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:08:17 by bwaterlo          #+#    #+#             */
/*   Updated: 2018/11/08 12:40:01 by bwaterlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		last_found;

	i = 0;
	last_found = -1;
	while (s[i])
	{
		if (s[i] == c)
			last_found = i;
		i++;
	}
	if (!c)
		return ((char *)&s[i]);
	if (last_found >= 0)
		return ((char *)&s[last_found]);
	return (NULL);
}
