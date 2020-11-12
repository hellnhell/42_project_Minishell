/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:47:03 by emartin-          #+#    #+#             */
/*   Updated: 2020/11/12 19:51:06 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pipes_first(t_tab *t, char **env)
{
	int 	status;
	pid_t	pid;
	
	pipe(t->fd1);
	
	pid = fork();
	if (pid == 0)
	{
		close(t->fd1[READ_END]);
		printf("fdREAD-----%d\n", t->fd1[READ_END]);
		printf("fdWRITE-----%d\n", t->fd1[WRITE_END]);
		dup2(t->fd1[WRITE_END], STDOUT_FILENO);
		printf("eins\n");
		close(t->fd1[WRITE_END]);
		if(check_our_implement(t))
		{
			read_path(t, env);
			check_path(t, env);
			kill(pid, 0);
			execve("/bin/ls", env, env);
		}
	}
	else
		wait(&status);

}

void	ft_pipes_mid(t_tab *t, char **env)
{
	int 	status;
	pid_t	pid;
	
	pipe(t->fd2);
	pid = fork();
	if (pid == 0)
	{
		close(t->fd2[READ_END]);

		dup2(t->fd1[READ_END], STDIN_FILENO);
		close(t->fd1[READ_END]);
		dup2(t->fd2[WRITE_END], STDOUT_FILENO);
		close(t->fd2[WRITE_END]);
		if (check_our_implement(t))
		{
			read_path(t, env);
			check_path(t, env);
			//execve("/bin/ls", env, env);
		}
	}
	waitpid(pid, &status, 0);
	printf("eins\n");
}

void	ft_pipes_end(t_tab *t, char **env)
{
	int 	status;
	pid_t	pid;

	pipe(t->fd2);
	close(t->fd1[READ_END]);
	close(t->fd2[WRITE_END]);


	pid = fork();
	if (pid == 0)
	{
		dup2(t->fd2[READ_END], STDIN_FILENO);
		close(t->fd2[READ_END]);
	}
	else
	{
		close(t->fd2[READ_END]);
		wait(&status);
	}
}
