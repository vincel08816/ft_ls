/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilee <vilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 20:08:41 by vilee             #+#    #+#             */
/*   Updated: 2020/01/29 16:52:44 by vilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	constructp(t_var *var)
{
	(*var).flags['-'] = 0;
	(*var).flags['+'] = 0;
	(*var).flags[' '] = 0;
	(*var).flags['#'] = 0;
	(*var).flags['0'] = 0;
	(*var).specifier = 0;
	ft_bzero((*var).length, 5);
	ft_bzero(var->append, 1000);
	(*var).hex_upper = 0;
	ft_bzero(var->pre_mod, 1000);
	(*var).check_num = 0;
	(*var).base = 0;
	(*var).ret_len = 0;
	(*var).wp->width = 0;
	(*var).wp->dot = 0;
	(*var).wp->after_dot = 0;
	(*var).wp->mem_print = 0;
	(*var).wp->str_print = 0;
	(*var).wp->tot_print = 0;
	(*var).bs->if_signed = 0;
	(*var).bs->tmp_num = 0;
	(*var).wp->mem_s = 0;
}

void	make_dpt(t_spec_funct *ref[127])
{
	ref['c'] = pf_spec_c;
	ref['s'] = pf_spec_s;
	ref['p'] = pf_spec_p;
	ref['d'] = pf_diouxx;
	ref['D'] = pf_diouxx;
	ref['i'] = pf_diouxx;
	ref['u'] = pf_diouxx;
	ref['b'] = pf_diouxx;
	ref['o'] = pf_diouxx;
	ref['x'] = pf_diouxx;
	ref['X'] = pf_diouxx;
	ref['f'] = pf_spec_f;
	ref['%'] = pf_spec_c;
}

void	add_hash(t_var *var, char **print)
{
	if (ft_strchr("oxX", var->specifier) && var->flags['#'])
	{
		if (!ft_strcmp("", var->pre_mod) || !ft_strcmp("0", var->pre_mod))
			return ;
		if (var->specifier == 'o')
			ft_strcat(*print, "0");
		else
			var->specifier == 'x' ? ft_strcat(*print, "0x") :\
			ft_strcat(*print, "0X");
		*print += (var->flags['#'] && ft_strchr("oxX", var->specifier) ?
		1 + (ft_strchr("xX", var->specifier) != 0) : 0);
	}
}
