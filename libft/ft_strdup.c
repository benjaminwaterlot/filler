/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaterlo <bwaterlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:00:38 by bwaterlo          #+#    #+#             */
/*   Updated: 2018/11/08 15:33:46 by bwaterlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;

	dest = ft_strnew(ft_strlen(s));
	if (!dest)
		return (NULL);
	ft_strcpy(dest, s);
	return (dest);
}
