/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaterlo <bwaterlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:17:08 by bwaterlo          #+#    #+#             */
/*   Updated: 2018/11/07 17:28:01 by bwaterlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_nb(long nb)
{
	if (nb > 9)
		print_nb(nb / 10);
	ft_putchar(nb % 10 + '0');
}

void		ft_putnbr(int nb)
{
	long	safe_nb;

	safe_nb = nb;
	if (safe_nb < 0)
	{
		ft_putchar('-');
		safe_nb *= -1;
	}
	print_nb(safe_nb);
}
