/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 11:48:05 by vilee             #+#    #+#             */
/*   Updated: 2019/08/09 14:04:59 by vilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** compares the characters within dest and src
** s1 > s2 means return > 0 | if return is 0, s1 is the same as s2
*/

int		ft_memcmp(void const *s1, void const *s2, size_t n)
{
	size_t			i;
	unsigned char	*cpy1;
	unsigned char	*cpy2;

	i = 0;
	cpy1 = (unsigned char*)s1;
	cpy2 = (unsigned char*)s2;
	while (i < n && (cpy1[i]) == (cpy2[i]))
		i++;
	if (i == n)
		return (0);
	else
		return (cpy1[i] - cpy2[i]);
}
