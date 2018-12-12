/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaterlo <bwaterlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:06:27 by bwaterlo          #+#    #+#             */
/*   Updated: 2018/11/12 14:55:51 by bwaterlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_string(char *string, long nb)
{
	int		i;

	if (nb > 9)
		get_string(string, nb / 10);
	i = 0;
	while (string[i])
		i++;
	string[i] = nb % 10 + '0';
	return (string);
}

char		*ft_itoa(int nb)
{
	char	*result;
	long	safe_nb;
	int		length;
	long	nb_decrement;

	length = 1;
	safe_nb = nb;
	if (safe_nb < 0)
	{
		safe_nb *= -1;
		length++;
	}
	nb_decrement = safe_nb;
	while (nb_decrement >= 10)
	{
		length++;
		nb_decrement /= 10;
	}
	if (!(result = ft_strnew(length)))
		return (NULL);
	if (nb < 0)
		result[0] = '-';
	get_string(result, safe_nb);
	return (result);
}
