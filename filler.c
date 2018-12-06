/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaterlo <bwaterlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 10:20:04 by bwaterlo          #+#    #+#             */
/*   Updated: 2018/12/06 13:33:05 by bwaterlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main()
{
	char	**board;
	char	**piece;

	open("./test", O_RDONLY);
	board = handle_input('b');
	printf("%s\n", board[1]);
	print_board(board);
	piece = handle_input('p');
	printf("%s\n", piece[1]);
	print_board(piece);
	return (0);
}
