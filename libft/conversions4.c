/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilee <vilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 20:09:02 by vilee             #+#    #+#             */
/*   Updated: 2020/01/29 16:52:44 by vilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_ullbase(va_list ap, t_var *var, int base)
{
	t_ulli	n;
	char	*s;
	char	tmp[100];

	ft_bzero(tmp, 100);
	s = &tmp[98];
	n = (t_ulli)va_arg(ap, unsigned long long);
	var->check_num = n == 0 ? 1 : 0;
	if (!n)
		return (ft_strdup("0"));
	while (n)
	{
		*(s--) = base_ret(n % base, var->hex_upper);
		n /= (t_ulli)base;
	}
	return (ft_strdup(s + 1));
}
