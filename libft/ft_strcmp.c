/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 16:06:45 by vilee             #+#    #+#             */
/*   Updated: 2019/08/10 16:08:17 by vilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*cp1;
	unsigned char	*cp2;
	int				i;

	cp1 = (unsigned char*)s1;
	cp2 = (unsigned char*)s2;
	i = 0;
	while (cp1[i] && cp2[i] && cp1[i] == cp2[i])
		i++;
	return (cp1[i] - cp2[i]);
}
