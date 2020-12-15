/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:47:03 by emartin-          #+#    #+#             */
/*   Updated: 2020/12/08 18:51:07 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		ft_pipes(t_tab *t)
{
	int		status;
	pid_t	pid;

	if (pipe(t->fd1) == 0)
	{
		pid = fork();
		if (pid == 0)
		{
			dup2(t->fd1[WRITE_END], STDOUT_FILENO);
			check_builtins(t);
			exit(0);
		}
		else if (pid > 0)
		{
			waitpid(pid, &status, 0);
			t->status = (status / 256);
			close(t->fd1[WRITE_END]);
			dup2(t->fd1[READ_END], STDIN_FILENO);
			close(t->fd1[READ_END]);
		}
	}
	else
		exit(-1);
}

void		ft_redi_pipe(t_tab *t, t_node *iterator)
{
	pid_t	pid;
	char	**str;

	str = ft_split_list(iterator->element, ' ', t);
	pipe(t->fd1);
	pid = fork();
	if (pid == 0)
	{
		t->fd1[READ_END] = open(str[0], O_RDONLY);
		if (t->fd1[READ_END] == -1)
			err_nodir_pipe(str);
		dup2(t->fd1[READ_END], STDIN_FILENO);
		dup2(t->fd1[WRITE_END], STDOUT_FILENO);
		check_builtins(t);
		exit(0);
	}
	else if (pid > 0)
	{
		waitpid(pid, &t->status, 0);
		close(t->fd1[WRITE_END]);
		dup2(t->fd1[READ_END], STDIN_FILENO);
		close(t->fd1[READ_END]);
	}
	free_matrix(str);
}
