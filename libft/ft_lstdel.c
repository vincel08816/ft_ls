/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 14:42:12 by vilee             #+#    #+#             */
/*   Updated: 2019/09/05 08:54:36 by vilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	similiar to iterative functions.
** hold the next pointer, edit current one.
*/

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*ptr;
	t_list	*now;

	if (!*alst)
		return ;
	ptr = *alst;
	while (ptr->next)
	{
		now = ptr;
		ptr = ptr->next;
		ft_lstdelone(&now, del);
	}
	ft_lstdelone(&ptr, del);
	*alst = NULL;
}
