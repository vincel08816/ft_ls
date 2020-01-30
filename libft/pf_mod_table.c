/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_mod_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilee <vilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 20:21:25 by vilee             #+#    #+#             */
/*   Updated: 2020/01/29 16:52:44 by vilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_var(char *print, va_list ap, t_var *var)
{
	int					jump;
	static t_spec_funct	*ref[127];

	jump = (int)var->specifier;
	!(ref['c']) ? make_dpt(ref) : 0;
	if (ref[(int)var->specifier] != 0)
		return (ref[(int)var->specifier](print, ap, var));
	return (0);
}

int		pf_spec_c(char *print, va_list ap, t_var *var)
{
	int		ret;
	int		i;
	char	c;

	i = -1;
	var->wp->width += (var->wp->width ? 0 : 1);
	var->flags['-'] ? var->flags['0'] = 0 : 0;
	c = (var->specifier == '%' ? '%' : (char)va_arg(ap, int));
	if (var->flags['-'])
		var->flags['0'] = 0;
	if (var->flags['-'] && var->wp->width - 1 >= 0)
	{
		ft_strcpy(print, &c);
		ft_memset((void*)(print + 1), ' ', var->wp->width - 1);
	}
	else
	{
		ft_memset((void*)(print), !var->flags['0'] ? \
		' ' : '0', var->wp->width - 1);
		ft_strcpy(print + var->wp->width - 1, &c);
	}
	var->ret_len = (var->wp->width ? var->wp->width : 1);
	ret = var->ret_len;
	return (ret);
}

int		pf_spec_p(char *print, va_list ap, t_var *var)
{
	long long	lltmp;
	char		*stmp;
	char		s[100];

	ft_bzero(s, 100);
	lltmp = va_arg(ap, long long);
	var->wp->after_dot = 0;
	var->wp->dot = 0;
	var->flags['0'] = 0;
	stmp = ft_lltoa_base((void*)&lltmp, var, 16);
	ft_strcat(s, "0x");
	ft_strcat(s + 2, stmp);
	var->ret_len = ft_strlen(s);
	t_length_width(print, var, s);
	free(stmp);
	return (0);
}

int		pf_diouxx(char *print, va_list ap, t_var *var)
{
	int		ret;
	char	s[100];
	char	*tmp;
	char	*ptr;

	ft_bzero(s, 100);
	tmp = pf_intlen3(ap, var);
	ptr = tmp;
	if (tmp[0] != '-' && (var->flags['+'] || var->flags[' ']))
		var->pre_mod[0] = (var->flags['+'] ? '+' : ' ');
	ft_strcat(var->pre_mod, ptr);
	free(tmp);
	pf_int2s(print, var);
	ret = var->ret_len;
	return (ret);
}

int		pf_spec_s(char *print, va_list ap, t_var *var)
{
	char *s;

	if (var->wp->dot && !var->wp->after_dot)
	{
		s = "";
		va_arg(ap, char *);
	}
	else
		s = va_arg(ap, char *);
	if (!s)
		s = "(null)";
	var->ret_len = ft_strlen(s);
	if (var->wp->width || var->wp->dot || var->wp->after_dot)
		t_length_width(print, var, s);
	else
		ft_strncat(print, s, var->ret_len);
	return (var->ret_len);
}
