/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 13:03:02 by vilee             #+#    #+#             */
/*   Updated: 2019/08/10 13:03:19 by vilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	similiar to strstr except there is a size_t boundary condition
**	s2 is the string being searched
**	ft_memcmp will compare the value of
**	the two strings within a specified length
*/

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t len;

	if (!ft_strcmp(s2, ""))
		return ((char *)s1);
	if ((!n || !s2) && !*s2)
		return ((char*)s1);
	if (!s1 && !s2)
		return (NULL);
	len = ft_strlen(s2);
	while (*s1 && n >= len)
	{
		if (*s1 == *s2 && !ft_memcmp(s1, s2, len))
			return ((char *)s1);
		s1++;
		n--;
	}
	return (NULL);
}
