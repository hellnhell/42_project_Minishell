/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 18:04:38 by emartin-          #+#    #+#             */
/*   Updated: 2020/11/12 19:44:44 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		not_command_error(t_tab *t)
{
	if (t->tokens[0][0] == '/')
	{
		ft_putstr_fd("bash: ", 1);
		ft_putstr_fd(t->tokens[0], 1);
		ft_putstr_fd(": ", 1);
		ft_putstr_fd("No such file or directory\n", 1);	
	}
	else
	{
		ft_putstr_fd("bash: ", 1);
		ft_putstr_fd(t->tokens[0], 1);
		ft_putstr_fd(": ", 1);
		ft_putstr_fd("command not found\n", 1);
	}
	exit(127); 
}


int		check_path(t_tab *t, char **env)
{
	int		i;
	int		j;
	char	*aux;
	char	*tmp;
	int		status;
	pid_t	pid;
	char	*buff;

	i = 0;
	buff = malloc(1024);
	getcwd(buff, 1024);
	pid = fork();
	if (pid == 0)
	{	
	//if (!t->tokens[0])
	//	printf("errrrrrroorrrrr\n");
	
		while(t->path[i])
		{ // Esto igual da error porque t->tokens[0] puede no existir
			if (t->tokens[0][0] == '.')
			{
				aux = ft_strjoin_sl2(buff, t->tokens[0]);
				tmp = aux;
				//printf("lo que estamos probando con el . es %s\n", tmp);
				j = execve(tmp, t->tokens, env);
				free(aux);
				if (j >= 0)
					continue ;
			}
			else if (t->tokens[0][0] == '/')
			{
				j = execve(t->tokens[0], t->tokens, env);
				if (j >= 0)
					continue ;
			}			
			aux = ft_strjoin_sl(t->path[i], t->tokens[0]);
			tmp = aux;
			j = execve(tmp, t->tokens, env);
			//printf("lo que estamos probando es %s\n", tmp);
			free(aux);
			i++;
		}
		if (j < 0)
			not_command_error(t);
	}
	else
	{
		waitpid(pid, &status, 0);
		t->status = (status / 256);
	}
	free(buff);
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
		//PROBAR "ASDAS" CON LOS CAMBIOS DE ISA
		if (ft_strncmp("PATH=", t->env[i], 5) == 0)
		{
			path = ft_split(&t->env[i][5], ':');
			ft_allocate_path(t, path);
			ft_cpy_path(t, path);
		}
		i++;
		
	}
}
