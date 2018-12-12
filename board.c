/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaterlo <bwaterlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 10:34:11 by bwaterlo          #+#    #+#             */
/*   Updated: 2018/12/12 16:57:27 by bwaterlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_size(char *specs, int *width, int *height)
{
	while (!ft_isdigit(*specs))
		specs++;
	*height = ft_atoi(specs);
	while (ft_isdigit(*specs))
		specs++;
	*width = ft_atoi(specs);
}

t_board	*create_board(void)
{
	t_board	*board;
	char	*temp_line;
	int		i;
	int		line_start;

	i = 0;
	get_next_line(FILLER_STD, &temp_line);
	board = (t_board *)ft_memalloc(sizeof(t_board));
	get_size(temp_line, &(board->width), &(board->height));
	board->value = (char **)ft_memalloc(sizeof(char *) * (board->height + 1));
	if (!ft_strncmp(temp_line, "Plateau", ft_strlen("Plateau")))
		get_next_line(FILLER_STD, &temp_line);
	while (i < board->height)
	{
		line_start = 0;
		get_next_line(FILLER_STD, &temp_line);
		while (!ft_strchr(".*OoXxCcDdEeFfM", temp_line[line_start]))
			line_start++;
		board->value[i] = ft_strdup(&temp_line[line_start]);
		free(temp_line);
		i++;
	}
	board->value[i] = 0;
	return (board);
}

t_piece	*create_piece(void)
{
	t_piece	*piece;
	char	*temp_line;
	int		i;
	int		line_start;

	i = 0;
	get_next_line(FILLER_STD, &temp_line);
	piece = (t_piece *)ft_memalloc(sizeof(t_piece));
	get_size(temp_line, &(piece->width), &(piece->height));
	piece->value = (char **)ft_memalloc(sizeof(char *) * (piece->height + 1));
	if (!ft_strncmp(temp_line, "Plateau", ft_strlen("Plateau")))
		get_next_line(FILLER_STD, &temp_line);
	while (i < piece->height)
	{
		line_start = 0;
		get_next_line(FILLER_STD, &temp_line);
		while (!ft_strchr(".*", temp_line[line_start]))
			line_start++;
		piece->value[i] = ft_strdup(&temp_line[line_start]);
		free(temp_line);
		i++;
	}
	piece->value[i] = 0;
	return (piece);
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

void	refine_piece(t_piece **piece)
{
	int		i;

	(*piece)->start_col = 0;
	while (is_empty_col(*piece, (*piece)->start_col))
	{
		(*piece)->start_col++;
		(*piece)->width--;
	}
	while (is_empty_col(*piece, (*piece)->start_col + (*piece)->width - 1))
	{
		(*piece)->width--;
	}
	(*piece)->start_line = 0;
	while (!ft_strchr((*piece)->value[(*piece)->start_line], '*'))
	{
		(*piece)->start_line++;
		(*piece)->height--;
	}
	i = (*piece)->height + (*piece)->start_line;
	while (i > 1 && !ft_strchr((*piece)->value[i - 1], '*'))
	{
		(*piece)->height--;
		i--;
	}
}

void	handle_input(t_board **board, t_piece **piece)
{
	*board = create_board();
	*piece = create_piece();
	refine_piece(piece);
}
