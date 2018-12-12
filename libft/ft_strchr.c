/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaterlo <bwaterlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:08:17 by bwaterlo          #+#    #+#             */
/*   Updated: 2018/11/08 15:33:37 by bwaterlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*s_cpy;

	s_cpy = (char *)s;
	if (!c)
		return (&s_cpy[ft_strlen(s)]);
	while (*s_cpy)
	{
		if (*s_cpy == c)
			return (s_cpy);
		s_cpy++;
	}
	return (NULL);
}
