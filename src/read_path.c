/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hellnhell <hellnhell@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 18:04:38 by emartin-          #+#    #+#             */
/*   Updated: 2020/11/05 20:59:26 by hellnhell        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		not_command_error(t_tab *t)
{
	ft_putstr_fd("bash: ", 1);
	ft_putstr_fd(t->tokens[0], 1);
	ft_putstr_fd(": ", 1);
	ft_putstr_fd("command not found\n", 1);
	exit(127); // aqui gestionar $?
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
		while(t->path[i])
		{
			aux = ft_strjoin_sl(t->path[i], t->tokens[0]);
			tmp = aux;
			j = execve(tmp, t->tokens, env);
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
	//printf("%d\n", status);
	return(0);
}

void	read_path(t_tab *t, char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		//t->our_env[i] = ft_strdup(env[i]);
		// Esto puede petar si nos dan una variable de entorno que se llame "PATH="
		//PROBAR "ASDAS" CON LOS CAMBIOS DE ISA
		if (ft_strncmp("PATH=", t->env[i], 5) == 0)
			t->path = ft_split(&t->env[i][5], ':');
		i++;
	}
}
