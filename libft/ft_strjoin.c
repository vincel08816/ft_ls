/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 09:05:59 by vilee             #+#    #+#             */
/*   Updated: 2019/09/05 09:06:03 by vilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	strcat should overwrite the null terminating byte on the original string.
**	and if 1 of the strings don't exist, return a copy of the existing string
**	if both strings don't exist, return NULL
**	if both strings exist return a appended version of s1 + s2
*/

static void		join_str(char const *s1, char const *s2, char **ret)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s1[i] && (*ret + i))
	{
		*(*ret + i) = s1[i];
		i++;
	}
	while (s2[j] && (*ret + i + j))
	{
		*(*ret + i + j) = s2[j];
		j++;
	}
	*(*ret + i + j) = '\0';
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*ret;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len = ft_strlen(s2) + ft_strlen(s1);
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	join_str(s1, s2, &ret);
	return (ret);
}
