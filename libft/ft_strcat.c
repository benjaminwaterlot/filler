/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaterlo <bwaterlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 12:51:02 by bwaterlo          #+#    #+#             */
/*   Updated: 2018/11/08 10:43:41 by bwaterlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, const char *src)
{
	int		dest_length;
	int		counter;

	dest_length = 0;
	while (dest[dest_length])
		++dest_length;
	counter = 0;
	while (src[counter])
	{
		dest[dest_length + counter] = src[counter];
		counter++;
	}
	dest[dest_length + counter] = '\0';
	return (dest);
}
