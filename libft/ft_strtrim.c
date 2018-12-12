/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaterlo <bwaterlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 19:10:38 by bwaterlo          #+#    #+#             */
/*   Updated: 2018/11/09 09:55:31 by bwaterlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_iswhitespace(int c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char		*ft_strtrim(const char *s)
{
	int		length;
	char	*scopy;
	char	*new_string;

	if (!s)
		return (NULL);
	scopy = (char *)s;
	while (ft_iswhitespace(*scopy))
		scopy++;
	length = ft_strlen(scopy);
	if (length)
	{
		while (ft_iswhitespace(scopy[--length]))
			;
		new_string = ft_strsub((const char *)scopy, 0, ++length);
	}
	else
		new_string = ft_strnew(0);
	return (new_string);
}
