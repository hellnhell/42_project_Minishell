/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 19:04:47 by nazurmen          #+#    #+#             */
/*   Updated: 2020/12/09 17:58:36 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void		print_error(char **args)
{
	ft_putstr_fd("cd: ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(args[0], 2);
}

static void		home_dir(char **env, int i)
{
	while (env[i])
	{
		if (ft_strncmp("HOME=", env[i], 5) == 0)
			chdir(env[i] + 5);
		i++;
	}
}

int				ft_cd(char **args, char **env)
{
	char		*path;
	int			i;

	i = 0;
	path = args[0];
	if (!path)
		home_dir(env, i);
	else if (-1 == (i = chdir(path)))
		print_error(args);
	else
	{
		i = 0;
		while (args[i])
		{
			path = ft_strjoin(path, args[i]);
			if (args[++i])
				path = ft_strjoin(path, " ");
			free(path);
		}
	}
	return (0);
}
