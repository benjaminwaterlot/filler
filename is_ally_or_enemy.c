/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ally_or_enemy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaterlo <bwaterlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:12:24 by bwaterlo          #+#    #+#             */
/*   Updated: 2018/12/12 16:14:42 by bwaterlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			is_ally(char c)
{
	return (c == g_game->player || c == g_game->player + 32);
}

int			is_enemy(char c)
{
	return (c != '.' && !is_ally(c));
}
