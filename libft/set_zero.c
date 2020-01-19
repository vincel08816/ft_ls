/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_zero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 09:13:31 by vilee             #+#    #+#             */
/*   Updated: 2019/09/05 09:13:41 by vilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**  this function sets i, j , k , l values to 0;
**	this function can set pointer values to 0 as well.
**	example:
**	set_zero(&i, &j, (size_t*)&ret, NULL);
*/

void	set_zero(size_t *i, size_t *j, size_t *k, size_t *l)
{
	if (i)
		*i = 0;
	if (j)
		*j = 0;
	if (k)
		*k = 0;
	if (l)
		*l = 0;
}
