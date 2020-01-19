/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 16:08:25 by vilee             #+#    #+#             */
/*   Updated: 2019/08/10 16:13:04 by vilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*cp1;
	unsigned char	*cp2;

	cp1 = (unsigned char*)s1;
	cp2 = (unsigned char*)s2;
	i = 0;
	if (!n)
		return (0);
	n++;
	while (--n && cp1[i] && cp2[i] && cp1[i] == cp2[i])
		i++;
	if (n > 0)
		return (cp1[i] - cp2[i]);
	return (0);
}
