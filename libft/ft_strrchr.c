/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 10:54:46 by vilee             #+#    #+#             */
/*   Updated: 2019/08/10 11:18:32 by vilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	looks for the last occurence of c
**	reverse of strchr
*/

char	*ft_strrchr(char const *s1, int c)
{
	char *ptr;

	ptr = 0;
	while (*s1)
	{
		if (*s1 == c)
			ptr = (char*)s1;
		s1++;
	}
	if (!c)
		return ((char *)s1);
	return (ptr);
}
