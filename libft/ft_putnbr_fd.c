/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaterlo <bwaterlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:55:24 by bwaterlo          #+#    #+#             */
/*   Updated: 2018/11/07 17:28:47 by bwaterlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_nb(long nb, int fd)
{
	if (nb > 9)
		print_nb(nb / 10, fd);
	ft_putchar_fd(nb % 10 + '0', fd);
}

void		ft_putnbr_fd(int nb, int fd)
{
	long	safe_nb;

	safe_nb = nb;
	if (safe_nb < 0)
	{
		ft_putchar_fd('-', fd);
		safe_nb *= -1;
	}
	print_nb(safe_nb, fd);
}
