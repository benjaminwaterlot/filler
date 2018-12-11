/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaterlo <bwaterlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 11:03:55 by bwaterlo          #+#    #+#             */
/*   Updated: 2018/12/11 13:19:1 by bwaterlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	print_char_colored(char c)
{
	if (c == 'O')
	{
		// fprintf(stderr, "\033[0;31m");
		fprintf(stderr, "O");
		fflush(NULL);
	}
	else if (c == 'X')
	{
		// fprintf(stderr, "\033[0;32m");
		fprintf(stderr, "X");
		fflush(NULL);
	}
}

void	print_board(t_board *board)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	// printf("\n================\n");
	// printf("Current board : \n");
	// printf("================\n");
	fprintf(stderr, "COUCOU DU CUL !\n");
	// (void)board;
	while (board->value[i])
	{
		while (board->value[i][j])
		{
			print_char_colored(board->value[i][j]);
			j++;
		}
		// fprintf(stderr, "%s\n", board->value[i]);
		i++;
	}
}

void	print_coords(t_coords *coords)
{
	// fprintf(stderr, "COORDS ARE [%i, %i]\n", coords->line, coords->col);
	printf("%i %i\n", coords->line, coords->col);
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
