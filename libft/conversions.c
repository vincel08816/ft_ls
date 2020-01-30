/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilee <vilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 20:09:07 by vilee             #+#    #+#             */
/*   Updated: 2020/01/29 16:52:44 by vilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		find_base(t_var *var)
{
	var->base = 10;
	if (ft_strchr("b", var->specifier))
		var->base = 2;
	if (ft_strchr("o", var->specifier))
		var->base = 8;
	if (ft_strchr("xX", var->specifier))
	{
		var->base = 16;
		var->hex_upper = (var->specifier == 'x' ? 0 : 1);
	}
	return (var->base);
}

size_t	pf_float_len(float f)
{
	int		len;

	len = 0;
	while (f >= 1)
	{
		f /= 10;
		len++;
	}
	return (f);
}

char	base_ret(int n, int upper)
{
	char	*hex_base[2];

	hex_base[0] = "0123456789abcdef";
	hex_base[1] = "0123456789ABCDEF";
	return (hex_base[upper][n]);
}

char	*ft_lltoa_base(void *num, t_var *var, int base)
{
	char				*s;
	char				tmp[100];
	t_ulli				n2;

	if (var->bs->if_signed == 1)
	{
		ft_bzero(tmp, 100);
		s = &tmp[98];
		n2 = *(t_ulli*)num;
		if (!n2)
			return (ft_strdup("0"));
		while (n2)
		{
			*(s--) = base_ret(n2 % base, var->hex_upper);
			n2 /= base;
		}
		return (ft_strdup(s + 1));
	}
	return (lltoa_base(num, var, base));
}

char	*lltoa_base(void *num, t_var *var, int base)
{
	long long	*n;
	long long	n1;
	char		*s;
	char		tmp[100];
	int			is_neg;

	ft_bzero(tmp, 100);
	s = &tmp[98];
	n = (long long*)num;
	n1 = *n;
	is_neg = (n1 < 0 ? 1 : 0);
	n1 *= (!is_neg ? 1 : -1);
	if (!n1)
		return (ft_strdup("0"));
	while (n1)
	{
		*(s--) = base_ret(n1 % base, var->hex_upper);
		n1 /= base;
	}
	*s = (is_neg ? '-' : 0);
	return ((is_neg ? ft_strdup(s) : ft_strdup(s + 1)));
}
