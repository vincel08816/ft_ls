/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 14:45:12 by vilee             #+#    #+#             */
/*   Updated: 2019/08/09 14:45:26 by vilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	The strdup() function returns a pointer to a new string which is a
**	duplicate of the string s.  Memory for the new string is obtained
**	with malloc(3), and can be freed with free(3).
*/

char	*ft_strdup(const char *s)
{
	int		i;
	char	*cpy;

	i = 0;
	if (!(cpy = (char *)malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	while (s[i])
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
