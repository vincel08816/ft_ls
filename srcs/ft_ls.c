/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilee <vilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:41:24 by vilee             #+#    #+#             */
/*   Updated: 2020/01/29 16:51:46 by vilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			main(int ac, char **av)
{
	int		flags[128];
	int		arg;

	if (ac >= 1)
	{
		arg = ls_setflag(ac, flags, av);
		ls_checkdir(ac, arg - 1, av, flags);
		arg--;
		if (ac - 1 == arg)
			ft_ls(flags, ".");
		else
			while (++arg < ac)
				ft_ls(flags, av[arg]);
	}
	return (0);
}

static void	ls_bigr2(int *flags, t_lsnode *root)
{
	if (root == NULL)
		return ;
	if (root->left)
		ls_bigr2(flags, root->left);
	if (root->name[0] != '.' || flags['a'])
		if (ft_strcmp(root->name, ".") && ft_strcmp(root->name, ".."))
			ft_ls(flags, root->name);
	if (root->right)
		ls_bigr2(flags, root->right);
}

void		ft_lsbigr(int *flags, char *av)
{
	struct dirent	*de;
	DIR				*dr;
	t_lsnode		*root;
	t_lsnode		*insert;

	root = NULL;
	dr = opendir(av);
	if (dr != NULL)
	{
		while ((de = readdir(dr)) != NULL)
		{
			insert = ls_createnode(de->d_name, av);
			ls_insertnode(&root, insert);
		}
		ls_bigr2(flags, root);
		ls_freetree(root);
		closedir(dr);
	}
}

void 	ft_ls(int *flags, char *av)
{
	struct dirent	*de;
	DIR				*dr;
	t_lsnode		*root;
	t_lsnode		*insert;
	char			*tmp;

	root = NULL;
	dr = opendir(av);
	if (dr != NULL)
	{
		while ((de = readdir(dr)) != NULL)
		{
			insert = ls_createnode(de->d_name, av);
			ls_insertnode(&root, insert);
		}
		g_flags.ls_traverse(flags, root);
		ls_freetree(root);
		if (flags['R'])
		{
			ft_printf("\n%s: \n", tmp = build_path(0, av));
			ft_lsbigr(flags, av);
			ft_printf("\n\n");
			free(tmp);
		}
		closedir(dr);
	}
}
