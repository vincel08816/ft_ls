/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 18:00:47 by vilee             #+#    #+#             */
/*   Updated: 2019/08/10 18:00:49 by vilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		skip_c(size_t *i, char const *str, char c)
{
	if (!*str)
		return ;
	while (*str && *str == c)
	{
		(*i)++;
		str++;
	}
}

static size_t	words(char const *str, char c)
{
	size_t i;
	size_t total_len;
	size_t wlen;

	set_zero(&i, &total_len, NULL, NULL);
	skip_c(&i, &str[i], c);
	while (str[i])
	{
		wlen = 0;
		skip_c(&i, &str[i], c);
		wlen = (word_len(&str[i], c));
		wlen != 0 ? total_len += 1 : 0;
		i += wlen;
	}
	return (total_len);
}

static char		**something(char **ret)
{
	if (!(ret = (char **)malloc(sizeof(char *) * 2)))
		return (NULL);
	ret[1] = ft_strdup("");
	ret[2] = 0;
	return (ret);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	**ret;

	set_zero(&i, &j, (size_t*)&ret, NULL);
	if (!(s) || words(s, c) == 0)
	{
		ret = something(ret);
		return (ret);
	}
	if (!(ret = (char **)malloc(sizeof(char *) * (words(s, c) + 1))))
		return (NULL);
	while (s[j] && i != words(s, c))
	{
		skip_c(&j, &s[j], c);
		if (!(ret[i] = (char *)malloc(sizeof(char) * (word_len(&s[j], c) + 1))))
			return (NULL);
		k = 0;
		while (s[j] != c && s[j])
			ret[i][k++] = s[j++];
		ret[i++][k] = '\0';
	}
	ret[i] = NULL;
	return (ret);
}
