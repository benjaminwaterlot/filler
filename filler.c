/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaterlo <bwaterlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 10:20:04 by bwaterlo          #+#    #+#             */
/*   Updated: 2018/12/12 14:48:54 by bwaterlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_enemy_position(t_game *game, t_board *board)
{
	int		i;
	int		j;

	i = 0;
	while (board->value[i])
	{
		j = 0;
		while (board->value[i][j])
		{
			if (is_enemy(board->value[i][j]))
			{
				game->enemy_line = i;
				game->enemy_col = j;
				game->initialized = 1;
				return ;
			}
			j++;
		}
		i++;
	}
}

int		main()
{
	t_board		*board;
	t_piece		*piece;
	t_coords	*result;
	// char		player;
	char		*temp_line;

	g_game = (t_game *)ft_memalloc(sizeof(t_game));
	// g_game->enemy_col = 3;
	// g_game->enemy_line = 3;

	get_next_line(FILLER_STD, &temp_line);
	if (temp_line[10] == '1')
		g_game->player = 'O';
	else if (temp_line[10] == '2')
		g_game->player = 'X';
	else if (temp_line[10] == '3')
		g_game->player = 'C';
	else if (temp_line[10] == '4')
		g_game->player = 'D';
	else if (temp_line[10] == '5')
		g_game->player = 'E';
	else if (temp_line[10] == '6')
		g_game->player = 'F';
	ft_memdel((void **)&temp_line);
	while (1)
	{
		handle_input(&board, &piece);
		if (!g_game->initialized)
			get_enemy_position(g_game, board);
		result = fill_board(board, piece);
		print_coords(result);
		fflush(NULL);
		ft_memdel((void **)&board);
		ft_memdel((void **)&board->value);
		ft_memdel((void **)&piece);
		ft_memdel((void **)&piece->value);
		if (!result->is_valid)
		{
			ft_memdel((void **)&result);
			break ;
		}
		ft_memdel((void **)&result);
	}
	ft_memdel((void **)&g_game);
	return (0);
}
