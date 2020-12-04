/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 18:04:38 by emartin-          #+#    #+#             */
/*   Updated: 2020/12/04 20:41:18 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <string.h>

static void		not_command_error(t_tab *t)
{
	reset_std23(t);
	if (t->tokens[0][0] == '/')
		ft_printf("mari: %s : No such file or directory\n", t->tokens[0]);
	else
		ft_printf("mari: %s : command not found\n", t->tokens[0]);
	exit(127);
}

int		check_path(t_tab *t)
{
	int		i;
	int		j;
	char	*aux;
	int		status;
	pid_t	pid;
	char	*buff;

	i = 0;
	j = -1;
	buff = malloc(1024);
	getcwd(buff, 1024);
	pid = fork();
	if (pid == 0)
	{	
		while(t->path[i] != NULL)
		{ // Esto igual da error porque t->tokens[0] puede no existir
			if ((t->tokens[0][0] == '.' && t->tokens[0][1] && t->tokens[0][1] == '/') || ft_isalpha(t->tokens[0][0]))
			{
				if (t->tokens[0][0] == '.')
					aux = ft_strjoin_sl2(buff, t->tokens[0]);
				else if (ft_isalpha(t->tokens[0][0]))
					aux = ft_strjoin_sl(buff, t->tokens[0]);
				j = execve(aux, t->tokens, t->env);
				free(aux);
				if (j >= 0)
					continue ;
			}
			if (t->tokens[0][0] == '/')
			{
				j = execve(t->tokens[0], t->tokens, t->env);
				if (j >= 0)
					continue ;
			}
			//printf("%s'\n", t->tokens[0]);
			aux = ft_strjoin_sl(t->path[i], t->tokens[0]);
			j = execve(aux, t->tokens, t->env);
			free(aux);
			i++;
		}
		if (j < 0 || t->path[i] == NULL)
			not_command_error(t);
	}
	else
	{
		//system("leaks minishell");
		signal(SIGINT, ft_signal_c1);
		signal(SIGQUIT, ft_signal_quit);
		waitpid(pid, &status, 0);
		t->status = (status / 256);
	}
	free(buff);
	free_matrix(t->path); //CAMBIADO
	//printf("%d\n", status);
	return(0);
}

void	read_path(t_tab *t)
{
	int		i;

	i = 0;
	while (t->env[i])
	{
		// Esto puede petar si nos dan una variable de entorno que se llame "PATH="
		if (ft_strncmp("PATH=", t->env[i], 5) == 0)
		{
			t->path = ft_split(&t->env[i][5], ':');
			break ;
		}
		i++;
	}
    if (!t->env[i])
	{
		t->path = malloc(sizeof(char *));
        t->path[0] = NULL;
	}
}
