/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:47:03 by emartin-          #+#    #+#             */
/*   Updated: 2020/11/13 19:18:27 by isfernan         ###   ########.fr       */
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
		//printf("fdREAD-----%d\n", t->fd1[READ_END]);
		//printf("fdWRITE-----%d\n", t->fd1[WRITE_END]);
		//write(STDOUT_FILENO, &t->fd1[WRITE_END], 64);
		//write(STDOUT_FILENO, "\n", 1);
		close(t->fd1[READ_END]);
		dup2(t->fd1[WRITE_END], STDOUT_FILENO);
		//write(2, &t->fd1[WRITE_END], 64);
		//write(2, "\n", 1);
		close(t->fd1[WRITE_END]);
		if(check_our_implement(t))
		{
			read_path(t, env);
			check_path(t, env);
			//execve("/bin/ls", env, env);
		}
		printf("kkajasd\n");
	}
	dup2(1, t->fd1[WRITE_END]);
	kill(pid, 0);
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
	int		n;

	pipe(t->fd2);
	close(t->fd1[READ_END]);


	write(2, "yogur\n", 6);
	printf("esto lo tendría que hacer\n");

	dup2(1, STDOUT_FILENO);
	pid = fork();
	if (pid == 0)
	{
		close(t->fd1[WRITE_END]);
		dup2(t->fd1[READ_END], STDIN_FILENO);
		printf("esto lo tendría que hacer\n");
		//n = STDOUT_FILENO;
		//write(2, &n, 1);
		close(t->fd1[READ_END]);
		if (check_our_implement(t))
		{
			read_path(t, env);
			check_path(t, env);
			//execve("/bin/ls", env, env);
		}
	}
	else
	{
		close(t->fd1[READ_END]);
		wait(&status);
	}
	kill(pid, 0);
}
