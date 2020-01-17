#include "ft_ls.h"

void	ls_simple(int *flags, t_lsnode *root)
{
	if (root == NULL)
		return ;
	if (root->left)
		ls_simple(flags, root->left);
	if (root->name[0] != '.' || flags['a'])
	{
		if (flags['l'])
		{
			// printf("root = %p \t", &root);
			print_long(root, flags);
		}
		else
			printf("%-25s", root->name);
	}
	if (root->right)
		ls_simple(flags, root->right);
}

static void	ls_bigr2(int *flags, t_lsnode *root)
{
	if (root == NULL)
		return ;
	if (root->left)
		ls_bigr2(flags, root->left);
	if (root->name[0] != '.' || flags['a'])
		ft_ls2(flags, root->name);
	if (root->right)
		ls_bigr2(flags, root->right);
}

void		ft_lsbigr(int *flags, char *av)
{
	struct dirent	*de;
	DIR				*dr;
	t_lsnode		*root;

	// printf("\n1\n");
	root = NULL;
	dr = opendir(av);
	if (dr != NULL)
	{
		while ((de = readdir(dr)) != NULL)
		{
			if (flags['t'])
				ls_inserttime1(flags, (de->d_name), &root);
			else
				ls_insertnode(flags, (de->d_name), &root);
		}
		ls_bigr2(flags, root);
		ls_freetree(root);
		closedir(dr);
	}
}

void 	ft_ls2(int *flags, char *av)
{
	struct dirent	*de;
	DIR				*dr;
	t_lsnode		*root;

	root = NULL;
	dr = opendir(av);
	if (dr != NULL)
	{
		while ((de = readdir(dr)) != NULL)
		{
		// use my dispatch table here later
			if (flags['t'])
				ls_inserttime1(flags, (de->d_name), &root);
			else
				ls_insertnode(flags, (de->d_name), &root);
		}
		ls_simple(flags, root);	// needs modifying here too
		ls_freetree(root);
		if (flags['R'])
		{
			printf("\n%s: \n", av);
			ft_lsbigr(flags, av);
			printf("\n\n");
		}
		closedir(dr);
	}
}

void	ft_ls(int ac, int arg, int *flags, char **av)
{
	if (ac - 1 == arg)
	{
		ft_ls2(flags, ".");
		exit (1);
	}
	else
	{
		while (++arg < ac)
		{
			ft_ls2(flags, av[arg]);
		}
	}
}

int			main(int ac, char **av)
{
	int		flags[128];
	int		arg;

	if (ac >= 1)
	{
		arg = ls_checkflag(ac, flags, av);
		ls_checkdir(ac, arg - 1, flags, av);
		ft_ls(ac, arg - 1, flags, av);
	}
	return (0);
}
