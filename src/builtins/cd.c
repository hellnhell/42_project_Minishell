/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 19:04:47 by nazurmen          #+#    #+#             */
/*   Updated: 2020/11/30 19:19:21 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void		home_dir(char **env, int i)
{
	while (env[i])
	{
		if (ft_strncmp("HOME=", env[i], 5) == 0)
			chdir(env[i] + 5);
		i++;
	}
}

int			ft_cd(char **args, char **env)
{
	char		*path;
	int			i;

	path = args[0];
	i = 0;
	if (!path)
		home_dir(env, i);
	else if (-1 == chdir(path))
		ft_printf("mari: cd: %s : No such file or directory\n", path);
	else
	{
		while (args[i])
		{
			path = ft_strjoin(path, args[i]);
			if (args[++i])
				path = ft_strjoin(path, " ");
		}
	}
	free(path);//LO PUSE
	return (0);
}
