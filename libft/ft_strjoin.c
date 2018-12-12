/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaterlo <bwaterlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 19:04:33 by bwaterlo          #+#    #+#             */
/*   Updated: 2018/11/08 19:09:59 by bwaterlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_troncon;

	if (!s1 || !s2)
		return (NULL);
	new_troncon = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!new_troncon)
		return (NULL);
	ft_strcpy(new_troncon, s1);
	ft_strcat(new_troncon, s2);
	return (new_troncon);
}
