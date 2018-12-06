/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaterlo <bwaterlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 10:34:11 by bwaterlo          #+#    #+#             */
/*   Updated: 2018/12/06 11:48:25 by bwaterlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		get_height(char *specs)
{
	while (!ft_isdigit(*specs))
		specs++;
	return (ft_atoi(specs));
}

char	**create_board(char *specs)
{
	char    **board;
	char	*temp_line;
	int		i;

	i = 0;
	board = (char **)ft_memalloc(sizeof(char *) * get_height(specs));
	while (get_next_line(0, &temp_line) > 0)
	{
		board[i] = ft_strdup(temp_line + 4);
		// free(&temp_line);
		i++;
	}
	board[i] = 0;
	return (board);
}

char	**create_piece(char *specs)
{
	char    **piece;
	int		i;

	i = 0;
	piece = (char **)ft_memalloc(sizeof(char *) * get_height(specs));
	while (get_next_line(0, &piece[i]))
		i++;
	piece[i] = 0;
	return (piece);
}

void	handle_input(char **board, char **piece)
{
	char	*current_line;

	get_next_line(0, &current_line);
	if (ft_strncmp(current_line, "Plateau", ft_strlen("Plateau")))
	{
		get_next_line(0, NULL);
		board = create_board(current_line);
	}
	if (ft_strncmp(current_line, "Piece", ft_strlen("Piece")))
		piece = create_piece(current_line);
}
