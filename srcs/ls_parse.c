#include "ft_ls.h"

static void	ls_flagzero(int *flags)
{
	flags['t'] = 0;
	flags['r'] = 0;
	flags['R'] = 0;
	flags['l'] = 0;
	flags['a'] = 0;
}


t_lsnode	*ls_createnode2(char *tmp)
{
	t_lsnode *new;

	new = NULL;
	printf("%s\n", tmp);
	if (!(new = (t_lsnode*)malloc(sizeof(t_lsnode))))
		exit (1);
	new->name = tmp;
	if (!(new->stat = (struct stat*)malloc(sizeof(struct stat))))
		exit (1);
	lstat(tmp, (new->stat));
	new->path = 0;
	new->full_path = 0;
	new->is_dir = 0;
	new->left = 0;
	new->right = 0;
	return (new);
}

/*
**	returns 1 when error
*/

int		ls_checkflag(int ac, int *flags, char **av)
{
	int		count;
	int		arg;

	ls_flagzero(flags);
	arg = 1;
	while(arg < ac && av[arg][0] == '-')
	{
		if (ft_strlen(av[arg]) == 1)
			return (arg);
		count = 1;
		while (av[arg][count] && ft_strchr(LS_FLAG_OPTIONS, av[arg][count]))
		{
			flags[av[arg][count]] = 1;
			count++;
		}
		if (av[arg][count] != 0)
		{
			printf("%s%c\nusage: ls [%s] [file ...]\n", \
			"ls: illegal option -- ", av[arg][count], LS_FLAG_OPTIONS);
			exit(1);
		}
		arg++;
	}
	return (arg);
}

void	ls_checkdir(int ac, int arg, int *flags, char **av)
{
	DIR				*dr;

	while (++arg < ac)
	{
		if (!(dr = opendir(av[arg])))
			printf("ls: %s: No such file or directory\n", av[arg]);
	}
}