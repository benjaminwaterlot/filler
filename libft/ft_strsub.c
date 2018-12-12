/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaterlo <bwaterlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:52:40 by bwaterlo          #+#    #+#             */
/*   Updated: 2018/11/08 19:04:07 by bwaterlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t length)
{
	char	*new_troncon;

	if (!s)
		return (NULL);
	new_troncon = ft_strnew(length);
	if (!new_troncon)
		return (NULL);
	return (ft_strncpy(new_troncon, &s[start], length));
}
