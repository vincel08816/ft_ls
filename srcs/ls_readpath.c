/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_readpath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilee <vilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 16:39:36 by vilee             #+#    #+#             */
/*   Updated: 2020/01/18 21:26:37 by vilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*build_path(char *s, char *old_path)
{
	char	*tmp;
	char	*new;

	if (!s)
	{
		if (old_path[0] == '~' || old_path[0] == '/' || old_path[0] == '.')
			return (ft_strdup(old_path));
		return (ft_strjoin("./", old_path));
	}
	tmp = ft_strjoin(old_path, "/");
	new = ft_strjoin(tmp, s);
	free(tmp);
	return (new);
}
