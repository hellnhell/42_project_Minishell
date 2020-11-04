/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 18:04:38 by emartin-          #+#    #+#             */
/*   Updated: 2020/11/04 19:28:29 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		not_command_error(t_tab *t)
{
	ft_putstr_fd("zsh : command not found: ", 1);
	ft_putstr_fd(t->tokens[0], 1);
	write(1, "\n", 2);	
	return(0);
}


int		check_path(t_tab *t, char **env)
{
	int		i;
	int		j;
	char	*aux;
	char	*tmp;
	int		status;
	pid_t	pid;

	i = 0;
	pid = fork();
	if (pid == 0)
	{	
	//if (!t->tokens[0])
	//	printf("errrrrrroorrrrr\n");
	
		while(t->path[i] && t->path[i + 1])
		{
			aux = ft_strjoin_sl(t->path[i], t->tokens[0]);
			tmp = aux;
			j = execve(tmp, t->tokens, env);
			free(aux);
			i++;
		}
		if (t->path[i])
		{
			printf("hola que tal------%s\n", t->path[i]);
			j = execve(t->path[i], t->tokens, env);
		}
		if (j < 0)
			not_command_error(t);
	}
	else
	{
		waitpid(pid, &status, 0);
		//t->status = (status / 256);
	}
	//printf("%d\n", status);
	return(0);
}


void	read_path(t_tab *t, char **env)
{
	int		i;
	char	*test;
	char	**path;

	i = 0;
	while (env[i])
	{
		//t->our_env[i] = ft_strdup(env[i]);
		// Esto puede petar si nos dan una variable de entorno que se llame "PATH="
		if (ft_strncmp("PATH=", t->env[i], 5) == 0)
		{
			path = ft_split(&t->env[i][5], ':');
			ft_allocate_path(t, path);
			ft_cpy_path(t, path);
		}
		i++;
	}
}
