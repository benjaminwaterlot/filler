/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaterlo <bwaterlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 10:20:04 by bwaterlo          #+#    #+#             */
/*   Updated: 2018/12/11 19:33:47 by bwaterlo         ###   ########.fr       */
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
	g_game->enemy_col = 3;
	g_game->enemy_line = 3;

	get_next_line(FILLER_STD, &temp_line);
	// player = temp_line[10] == 1 ? 'O' : 'X';
	g_game->player = temp_line[10] == 1 ? 'O' : 'X';
	ft_memdel((void **)&temp_line);
	while (1)
	{
		handle_input(&board, &piece);
		if (!g_game->initialized)
			get_enemy_position(g_game, board);
		result = fill_board(board, piece);
		print_coords(result);
		fflush(NULL);
		// ft_memdel((void **)&board);
		// ft_memdel((void **)&piece);
		if (!result->is_valid)
		{
			ft_memdel((void **)&result);
			fprintf(stderr, "CANNOT PUT : height : piece of height %i and width %i\n", piece->height, piece->width);
			fflush(NULL);
			break ;
		}
		ft_memdel((void **)&board);
		ft_memdel((void **)&piece);
		ft_memdel((void **)&result);
	}
	return (0);
}
