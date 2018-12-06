/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaterlo <bwaterlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 11:03:55 by bwaterlo          #+#    #+#             */
/*   Updated: 2018/12/06 17:29:54 by bwaterlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	print_board(t_board *board)
{
	int		i;

	i = 0;
	printf("\n================\n");
	printf("Current board : \n");
	printf("================\n");
	while (board->value[i])
	{
		printf("%s\n", board->value[i]);
		i++;
	}
}

void	print_coords(t_coords *coords)
{
	printf("COORDS ARE [%i, %i]\n", coords->line, coords->col);
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
