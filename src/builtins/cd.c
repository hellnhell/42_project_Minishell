/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 19:04:47 by nazurmen          #+#    #+#             */
/*   Updated: 2020/11/10 19:57:01 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_cd(char **args, char **env)
{
	char *path;
	int i;

	path = args[0];
	i = 0;
	if(!path)
	{
		while (env[i])
		{
			// Esto puede petar si nos dan una variable de entorno que se llame "P
			if (ft_strncmp("HOME=", env[i], 5) == 0)
			{
				printf("path --- %s\n", path);
				chdir(env[i] + 5);
				
			}
		
			i++;
		}
	}
	else if (-1 == chdir(path))
	{
		ft_putstr_fd("cd: no such file or directory: ", 1);
		ft_putstr_fd(path, 1);
		ft_putchar_fd('\n', 1);
	}
	/*else 
	{
		while (args[i])
		{
			path = ft_strjoin(path, args[i]);
			if (args[++i])
				path = ft_strjoin(path, " ");
		}
	}*/
	return(0);
}
