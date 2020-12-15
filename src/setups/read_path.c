/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 18:04:38 by emartin-          #+#    #+#             */
/*   Updated: 2020/12/15 17:42:07 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <string.h>

int			relat_path(char *aux, char *buff, t_tab *t, int *j)
{
	if ((t->tokens[0][0] == '.' && t->tokens[0][1]
			&& t->tokens[0][1] == '/') || ft_isalpha(t->tokens[0][0]))
	{
		if (t->tokens[0][0] == '.')
			aux = ft_strjoin_sl2(buff, t->tokens[0]);
		else if (ft_isalpha(t->tokens[0][0]))
			aux = ft_strjoin_sl(buff, t->tokens[0]);
		*j = execve(aux, t->tokens, t->env);
		free(aux);
		return (1);
	}
	return (0);
}

void		exe_commands(t_tab *t, char *buff)
{
	int		i;
	int		*j;
	char	*aux;

	j = malloc(sizeof(int));
	i = 0;
	*j = -1;
	while (t->path[i] != NULL)
	{
		if (!relat_path(aux, buff, t, j) && *j >= 0)
			continue ;
		if (t->tokens[0][0] == '/')
		{
			*j = execve(t->tokens[0], t->tokens, t->env);
			if (*j >= 0)
				continue ;
		}
		aux = ft_strjoin_sl(t->path[i], t->tokens[0]);
		*j = execve(aux, t->tokens, t->env);
		free(aux);
		i++;
	}
	if (*j < 0 || t->path[i] == NULL)
		not_command_error(t);
	free(j);
}

int			check_path(t_tab *t)
{
	pid_t	pid;
	char	*buff;

	buff = malloc(1024);
	getcwd(buff, 1024);
	pid = fork();
	if (pid == 0)
		exe_commands(t, buff);
	else
	{
		signal(SIGINT, ft_signal_c1);
		signal(SIGQUIT, ft_signal_quit);
		waitpid(pid, &t->status, 0);
		t->status = (t->status / 256);
	}
	free(buff);
	free_matrix(t->path);
	return (0);
}

void		read_path(t_tab *t)
{
	int		i;

	i = 0;
	while (t->env[i])
	{
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
