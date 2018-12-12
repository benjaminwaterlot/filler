/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaterlo <bwaterlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:40:42 by bwaterlo          #+#    #+#             */
/*   Updated: 2018/11/12 16:52:57 by bwaterlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\f' || c == '\n'
	|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

static int	recurse(const char *string, long long number, int digits)
{
	number += (*string - 48);
	if (number < LONG_MIN)
		return (0);
	if (number > LONG_MAX)
		return (-1);
	if (digits <= 1)
		return (number);
	return (recurse(string + 1, number * 10, digits - 1));
}

int			ft_atoi(const char *source)
{
	int		start;
	int		sign;
	int		digits;

	start = 0;
	sign = 1;
	while (ft_isspace(source[start]))
		start++;
	if (source[start] == '+')
		start++;
	else if (source[start] == '-')
	{
		start++;
		sign = -1;
	}
	digits = 0;
	while (ft_isdigit(source[start + digits]))
		digits++;
	if (digits == 0)
		return (0);
	return (sign > 0
		? recurse(&source[start], 0, digits)
		: -recurse(&source[start], 0, digits));
}
