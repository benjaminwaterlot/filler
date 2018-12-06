/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaterlo <bwaterlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 10:20:04 by bwaterlo          #+#    #+#             */
/*   Updated: 2018/12/06 11:25:42 by bwaterlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main()
{
	char	**board;
	char	**piece;

	board = NULL;
	piece = NULL;
	handle_input(board, piece);
	print_board(board);
	print_board(piece);
	return (0);
}
