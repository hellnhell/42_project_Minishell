/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 18:04:38 by emartin-          #+#    #+#             */
/*   Updated: 2020/10/29 18:59:09 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		not_command_error(t_tab *t)
{
	ft_putstr_fd("zsh : command not found: ", 1);
	ft_putstr_fd(t->tokens[0], 1);
	write(1, "\n", 2);	
	exit(0);
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
		waitpid(pid, &status, 0);
	printf("%d\n", status);
	return(1);
}

void	read_path(t_tab *t, char **env)
{
	int		i;
	char *test;

	i = 0;
	while (env[i])
	{
		//t->our_env[i] = ft_strdup(env[i]);
		// Esto puede petar si nos dan una variable de entorno que se llame "PATH="
		if (ft_strncmp("PATH=", env[i], 5) == 0)
			t->path = ft_split(&env[i][5], ':');
		i++;
	}
}
