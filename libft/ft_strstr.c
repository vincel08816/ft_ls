/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 12:42:56 by vilee             #+#    #+#             */
/*   Updated: 2019/08/10 12:43:20 by vilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t i;

	if (!*s2 & !*s1)
		return ((char *)s1);
	while (*s1)
	{
		i = 0;
		while (s1[i] && s2[i] == s1[i])
			i++;
		if (!s2[i])
			return ((char*)s1);
		s1++;
	}
	return (NULL);
}
