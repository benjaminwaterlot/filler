/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaterlo <bwaterlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:24:23 by bwaterlo          #+#    #+#             */
/*   Updated: 2018/12/12 17:20:40 by bwaterlo         ###   ########.fr       */
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

int		throw_usage(void)
{
	ft_putstr("Invalid input. Program should be used with filler_vm only.\n");
	return (0);
}

int		is_empty_col(t_piece *piece, int col)
{
	int		i;

	i = 0;
	while (i < piece->height)
	{
		if (piece->value[i][col] != '.')
			return (0);
		i++;
	}
	return (1);
}
