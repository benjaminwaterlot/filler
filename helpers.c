/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaterlo <bwaterlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:24:23 by bwaterlo          #+#    #+#             */
/*   Updated: 2018/12/12 17:07:04 by bwaterlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	print_coords(t_coords *coords)
{
	ft_putnbr(coords->line);
	ft_putchar(' ');
	ft_putnbr(coords->col);
	ft_putchar('\n');
}

int		full_of_digits(char *string)
{
	while (*string)
	{
		if (!ft_isdigit(*string) && *string != ' ')
			return (0);
		string++;
	}
	return (1);
}

int		throw_usage(void)
{
	ft_putstr("Invalid input. Program should be used with filler_vm only.\n");
	return (0);
}
