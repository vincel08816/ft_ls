/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilee <vilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 18:47:16 by vilee             #+#    #+#             */
/*   Updated: 2020/01/29 16:51:46 by vilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ls_flagzero(int *flags)
{
	flags['t'] = 0;
	flags['r'] = 0;
	flags['R'] = 0;
	flags['l'] = 0;
	flags['a'] = 0;
}

static void		ls_init_options(int *flags)
{
	if (flags['l'])
		g_flags.ls_ft_printformat = &print_long;
	else
		g_flags.ls_ft_printformat = &print_norm;
	if (flags['r'])
		g_flags.ls_traverse = &print_reverse;
	else
		g_flags.ls_traverse = &print_inorder;
	if (flags['t'])
		g_flags.ls_sortcmp = &ls_timecmp;
	else
		g_flags.ls_sortcmp = &ls_strcmp;
}

int		ls_setflag(int ac, int *flags, char **av)
{
	int		count;
	int		arg;

	ls_flagzero(flags);
	arg = 0;
	while (++arg < ac && av[arg][0] == '-')
	{
		if (ft_strlen(av[arg]) == 1)
			return (arg);
		count = 1;
		while (av[arg][count] && ft_strchr(LS_FLAG_OPTIONS, av[arg][count]))
		{
			flags[(int)av[arg][count]] = 1;
			count++;
		}
		if (av[arg][count] != 0)
		{
			ft_printf("%s%c\nusage: ls [%s] [file ...]\n", \
			"ls: illegal option -- ", av[arg][count], LS_FLAG_OPTIONS);
			exit(1);
		}
	}
	ls_init_options(flags);
	return (arg);
}

void	ls_checkdir(int ac, int arg, char **av, int *flags)
{
	DIR				*dr;
	struct stat		check;
	char			*tmp[9999];
	int				i;
	t_lsnode		*root;
	
	i = 0;
	root = NULL;
	while (++arg < ac)
		if (!(dr = opendir(av[arg])))
			if (lstat(tmp[i++] = build_path(av[arg], "."), &check) == -1)
				ft_printf("ls: %s: No such file or directory\n", av[arg]);
	arg = 0;
	while (++arg < ac)
		if (lstat(tmp[i++] = build_path(av[arg], "."), &check) != -1)
			ls_insertnode(&root, ls_createnode(av[arg], "."));
	tmp[i] = NULL;
	if (root)
	{
		g_flags.ls_traverse(flags, root);
		ls_freetree(root);
		i = 0;
		while (tmp[i] != NULL)
			free(tmp[i++]);
	}
}
