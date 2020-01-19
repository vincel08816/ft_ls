/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilee <vilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 18:01:06 by vilee             #+#    #+#             */
/*   Updated: 2019/12/08 20:37:50 by vilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	takes of spaces in the front and the back of the string
**	f is the pointer to the front
**	b is the pointer to the back
*/

static void		check(size_t *l, size_t *f, size_t *b, char const *s)
{
	size_t len;

	*l = 0;
	*f = 0;
	len = ft_strlen(s);
	*b = len - 1;
	while (--len)
	{
		ft_isspace(s[*f]) ? (*f)++ : 0;
		ft_isspace(s[*b]) ? (*b)-- : 0;
	}
}

char			*ft_strtrim(char const *s)
{
	size_t	f;
	size_t	b;
	size_t	i;
	char	*ret;

	if (!s || !*s)
		return (ft_strdup(""));
	check(&i, &f, &b, s);
	if (f > b || b < f)
		return (ft_strdup(""));
	if (!(ret = (char *)malloc(sizeof(char) * (b - f + 2))))
		return (NULL);
	while (f <= b)
		ret[i++] = s[f++];
	ret[i] = '\0';
	return (ret);
}
