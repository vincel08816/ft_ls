#include "ft_ls.h"

t_lsnode	*ls_createnode(char *tmp)
{
	t_lsnode *new;

	printf("%s\n", tmp);
	new = NULL;
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

void	ls_insertnode(int *flags, char *tmp, t_lsnode **root)
{
	if (*root == NULL)
	{
		*root = ls_createnode(tmp);
		return ;
	}
	if (ft_strcmp((*root)->name, tmp) < 0)
		ls_insertnode(flags, tmp, &((*root)->right));
	else
		ls_insertnode(flags, tmp, &((*root)->left));
}

static void	ls_inserttime(time_t t, int *flags, char *tmp, t_lsnode **root)
{
	if (*root == NULL)
	{
		*root = ls_createnode(tmp);
		return ;
	}
	if ((*root)->stat->st_mtime > t)
		ls_inserttime(t, flags, tmp, &((*root)->right));
	else
		ls_inserttime(t, flags, tmp, &((*root)->left));
}

void	ls_inserttime1(int *flags, char *tmp, t_lsnode **root)
{
	struct stat	buf;

	stat(tmp, &buf);
	ls_inserttime(buf.st_mtime, flags, tmp, root);
}

void	ls_freetree(t_lsnode *tmp)
{
	if (tmp == NULL)
		return ;
	if (tmp->left)
		ls_freetree(tmp->left);
	if (tmp->right)
		ls_freetree(tmp->right);
	free(tmp);
}