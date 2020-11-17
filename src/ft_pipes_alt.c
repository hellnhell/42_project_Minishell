/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipes_alt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 19:06:38 by emartin-          #+#    #+#             */
/*   Updated: 2020/11/17 19:18:31 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_pipes_first(t_tab *t, char **env)
{
	int		status;
	pid_t	pid;

	pipe(t->fd1);
	pid = fork();
	if (pid == 0)
	{
		dup2(t->fd1[WRITE_END], STDOUT_FILENO);
		check_builtins(t, env);
		exit(0);
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		close(t->fd1[WRITE_END]);
		dup2(t->fd1[READ_END], STDIN_FILENO);
		close(t->fd1[READ_END]);
	}
}

