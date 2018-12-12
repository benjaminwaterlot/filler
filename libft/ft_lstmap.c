/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaterlo <bwaterlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:28:56 by bwaterlo          #+#    #+#             */
/*   Updated: 2018/11/12 09:48:33 by bwaterlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *cursor, t_list *(f)(t_list *elem))
{
	t_list	*new_elem;

	if (!cursor)
		return (NULL);
	new_elem = f(ft_lstnew(cursor->content, cursor->content_size));
	if (!new_elem)
		return (NULL);
	if (cursor->next)
		new_elem->next = ft_lstmap(cursor->next, f);
	return (new_elem);
}
