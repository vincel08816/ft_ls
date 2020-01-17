/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilee <vilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 16:13:19 by vilee             #+#    #+#             */
/*   Updated: 2019/12/08 20:38:07 by vilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int i;
	int num;
	int neg;

	i = 0;
	num = 0;
	neg = 1;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		(str[i++] == '-') ? (neg = -1) : 0;
	while (str[i] >= '0' && str[i] <= '9')
		num = num * 10 + str[i++] - '0';
	return (num * neg);
}
