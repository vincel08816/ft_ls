/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_floats2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilee <vilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 20:16:06 by vilee             #+#    #+#             */
/*   Updated: 2020/01/29 16:52:44 by vilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		pf_float_width(t_var *var, char c)
{
	int		len;
	char	memtmp;
	char	*ptr;

	ptr = var->append;
	var->wp->width = (var->wp->width > \
	(len = ft_strlen(var->pre_mod)) ? var->wp->width : len);
	if (var->wp->width > len && ft_strchr("+ -", c))
		var->wp->width--;
	var->flags[' '] ? var->append[0] = '0' && ptr++ : 0;
	if (!var->flags['-'])
	{
		if (var->wp->width > len)
		{
			memtmp = (var->flags['0']) ? '0' : ' ';
			ft_memset(ptr, (int)memtmp, var->wp->width - len);
		}
		ft_strcat(ptr, var->pre_mod);
	}
	else
	{
		ft_strcat(ptr, var->pre_mod);
		if (var->wp->width > len)
			ft_memset(ptr + len, (int)' ', var->wp->width - len);
	}
}

int				pf_spec_f(char *print, va_list ap, t_var *var)
{
	char *s;

	var->wp->after_dot += (!var->wp->after_dot && !var->wp->dot ? 6 : 0);
	if (!ft_strcmp("L", var->length))
		s = ft_ftoa(va_arg(ap, long double), var->wp->after_dot);
	else
		s = ft_ftoa(va_arg(ap, double), var->wp->after_dot);
	if (s[0] != '-' && (var->flags['+'] || var->flags[' ']))
		var->pre_mod[0] = (var->flags['+'] ? '+' : ' ');
	(s[0] != '-' && (var->flags['+'] || var->flags[' '])) ? \
	ft_strcat(&(var->pre_mod[1]), s) : ft_strcat(var->pre_mod, s);
	pf_float_width(var, s[0]);
	free(s);
	ft_strcat(print, var->append);
	var->ret_len = ft_strlen(print);
	return (var->ret_len);
}
