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

void	print_coords(t_coords *coords)
{
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
