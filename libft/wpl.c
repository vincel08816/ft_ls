/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wpl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilee <vilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 20:11:55 by vilee             #+#    #+#             */
/*   Updated: 2020/01/29 16:52:44 by vilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		t_length_width(char *print, t_var *var, char *s)
{
	t_width	*p;

	p = var->wp;
	p->str_print = var->ret_len > p->after_dot && \
	p->after_dot && p->dot ? p->after_dot : var->ret_len;
	p->mem_print = p->width > p->str_print ? p->width - p->str_print : 0;
	p->tot_print = p->str_print + p->mem_print;
	if (var->flags['-'])
	{
		ft_strncat(print, s, p->str_print);
		ft_memset((void*)(print + p->str_print), (int)' ', p->mem_print);
	}
	else
	{
		ft_memset((void*)print, var->flags['0'] ? '0' : ' ', p->mem_print);
		ft_strncat(print + p->mem_print, s, p->str_print);
	}
	var->ret_len = p->tot_print;
}

static void	pf_setint2(t_var *v, t_intparse *t, t_width *p)
{
	if (v->wp->after_dot)
		v->flags['0'] = 0;
	v->specifier == 'b' ? v->flags['#'] = 0 : 0;
	if (ft_strchr("oxX", v->specifier) && v->flags['#'] && !v->check_num)
		t->if_hash += 1 + (ft_strchr("xX", v->specifier) != 0);
	if (p->after_dot > (t->len = (int)ft_strlen(v->pre_mod)))
		t->pre_pad = t->len + (p->width > p->after_dot && \
		p->width > t->len ? t->if_hash : 0);
	else
		t->pre_pad = t->len + t->if_hash;
	if (v->specifier == 'o' && p->after_dot > t->len && p->width > t->len)
		t->pre_pad = t->len;
	t->pad = (p->width > p->after_dot ? p->width : p->after_dot) - t->pre_pad;
}

static void	pf_int4s(t_var *v, t_width *p, t_intparse *t)
{
	if (ft_strchr(" +-", v->pre_mod[0]))
	{
		if (p->after_dot > t->len)
		{
			(p->after_dot > t->len) ? t->print_zero++ : t->print_space++;
			if (t->pad + 1 >= t->print_space + t->print_zero && t->print_space)
				t->print_space--;
		}
		else
		{
			if (p->width > t->len && p->width > p->after_dot &&
			p->after_dot >= t->len)
			{
				t->print_space--;
				t->print_zero++;
			}
		}
	}
}

static void	pf_int3s(t_var *v, t_width *p, t_intparse *t)
{
	pf_int4s(v, p, t);
	if (ft_strchr("diub", v->specifier) && \
	(v->check_num && !v->wp->after_dot && v->wp->dot))
		t->print_space++;
	if (v->flags['#'] && ft_strchr("oxX", v->specifier))
	{
		(v->specifier == 'o' && t->print_zero && \
		v->flags['#'] && !v->check_num) ? t->print_zero-- : 0;
		if (p->width > p->after_dot && p->width > \
		t->len && v->specifier != 'o')
		{
			if ((t->print_space - t->if_hash > 0) && p->after_dot)
			{
				t->print_space -= t->if_hash;
				if (ft_strchr("xX", v->specifier))
					t->print_zero += t->if_hash;
			}
		}
	}
}

void		pf_int2s(char *print, t_var *v)
{
	t_width		*p;
	t_intparse	t;

	t = (t_intparse){0, 0, 0, 0, 0, 0};
	pf_setint2(v, &t, (p = v->wp));
	if ((p->width > p->after_dot ? p->width : p->after_dot) > t.pre_pad)
	{
		if (p->after_dot > p->width)
			t.print_zero = p->after_dot - t.pre_pad;
		else if (p->after_dot > t.pre_pad)
		{
			t.print_zero = p->after_dot - t.pre_pad;
			t.print_space = t.pad - t.print_zero;
		}
		else
			t.print_space = t.pad;
		pf_int3s(v, p, &t);
		pf_iiappend(print, v, &t);
		return ;
	}
	add_hash(v, &print);
	pf_intcats(print, v, v->pre_mod);
}
