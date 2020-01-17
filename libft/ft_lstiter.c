/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 14:43:05 by vilee             #+#    #+#             */
/*   Updated: 2019/08/16 14:43:06 by vilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** iterates the string by the function in parameter
**	original list
**	|  1				2				3
**	+---+---+     +---+---+       +----+------+
**	| 1  | o----->|  2  | o-----> |  3 | NULL |
**	+---+---+     +---+---+       +----+------+
**	|
**	|	after applied function
**	|	f(1) is applied to all the elements of the list
**	|  1				2				3
**	+---+---+     	+---+---+      +----+------+
**	|f(1)| o----->| f(2)| o-----> |f(3) | NULL |
**	+---+---+     	+---+---+      +----+------+
*/

void	ft_lstiter(t_list *alst, void (*f)(t_list *elem))
{
	if (!alst)
		return ;
	while (alst)
	{
		f(alst);
		alst = alst->next;
	}
}
