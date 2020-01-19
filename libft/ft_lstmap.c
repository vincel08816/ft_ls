/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 14:43:22 by vilee             #+#    #+#             */
/*   Updated: 2019/08/16 14:43:25 by vilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	part 1
**	head
**	|  1				2				3
**	+---+---+     +---+---+       +----+------+
**	| 1  | o----->|  2  | o-----> |  3 | NULL |
**	+---+---+     +---+---+       +----+------+
**	part 2
**	|
**	stack
**	3rd recursion 	2nd recursion	1st recursion
**	returns to 2	returns to 1	returns  head to function call
**	+---+---+     	+---+---+      	+----+------+
**	| f(3)  |	  	|  f(2) |	  	| 	f(1)	|
**	+---+---+     	+---+---+      	+----+------+
**	3, 2, 1 are elements of the original list
*/

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;

	if (lst)
	{
		ret = (*f)(lst);
		ret->next = ft_lstmap(lst->next, (*f));
		return (ret);
	}
	return (NULL);
}
