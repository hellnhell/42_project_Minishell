/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 20:29:09 by emartin-          #+#    #+#             */
/*   Updated: 2020/11/25 18:36:21 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "minishell.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

/*void			ft_pipes2(t_shell *f)
{
	pipe(f->fd1);
	f->pid = fork();
	if (f->pid == 0)
	{
		dup2(f->fd1[WRITE_END], STDOUT_FILENO);
		if (f->c == 1)
		{
			ft_body_redi(f);
		}
		else
			ft_body(f);
		exit(0);
	}
	else if (f->pid > 0)
	{
		waitpid(f->pid, &f->status, 0);
		close(f->fd1[WRITE_END]);
		dup2(f->fd1[READ_END], STDIN_FILENO);
		close(f->fd1[READ_END]);
	}
}*/



int main()
{
	char s[11];
	
	int fd = open("cosas.txt", O_RDONLY);
	read(fd, s, 10);
	printf("|%s|\n", s);
}