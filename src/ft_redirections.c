/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirections.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 18:02:50 by emartin-          #+#    #+#             */
/*   Updated: 2020/12/07 20:53:22 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_redi_greater(t_tab *t, node *iterator)
{
	char	**str;
	int		fd;

	str = ft_split_list(iterator->element, ' ', t);
	fd = open(str[0], O_WRONLY | O_TRUNC | O_CREAT, 0640);
	dup2(fd, STDOUT_FILENO);
	check_builtins(t);
	reset_stdout(t);
	dup2(fd, STDIN_FILENO);
	free_matrix(str);
}

void		ft_redi_less(t_tab *t, node *iterator)
{
	char	**str;

	str = ft_split_list(iterator->element, ' ', t);
	if (pipe(t->fd1) == 0)
	{
		t->fd1[READ_END] = open(str[0], O_RDONLY);
		if (t->fd1[READ_END] == -1)
		{
			ft_printf("mari: %s: No such file or directory\n", str[0]);
			t->status = 1;
			free_matrix(str);
			return ;
		}
		dup2(t->fd1[READ_END], STDIN_FILENO);
		check_builtins(t);
		close(t->fd1[WRITE_END]);
		close(t->fd1[READ_END]);
		free_matrix(str);
	}
	else
	{
		free_matrix(str);
		exit(-1);
	}
}

void		ft_redi_double(t_tab *t, node *iterator)
{
	char	**str;
	int		fd;

	str = ft_split_list(iterator->element, ' ', t);
	fd = open(str[0], O_WRONLY | O_APPEND | O_CREAT, 0640);
	dup2(fd, STDOUT_FILENO);
	check_builtins(t);
	reset_stdout(t);
	dup2(fd, STDIN_FILENO);
	free_matrix(str);
}

void		ft_redi_redi(t_tab *t, node *iterator, char c)
{
	char	**s1;
	char	**s2;

	s1 = ft_split_list(iterator->element, ' ', t);
	s2 = ft_split_list(iterator->next->element, ' ', t);
	pipe(t->fd1);
	t->fd1[READ_END] = open(s1[0], O_RDONLY);
	if (c == '>')
		t->fd1[WRITE_END] = open(s2[0], O_WRONLY | O_TRUNC
							| O_CREAT, 0640);
	else if (c == '-')
		t->fd1[WRITE_END] = open(s2[0], O_WRONLY | O_APPEND
							| O_CREAT, 0640);
	if (t->fd1[READ_END] == -1)
	{
		ft_printf("bash: %s: No such file or directory\n", s1[0]);
		t->status = 1;
		return ;
	}
	dup2(t->fd1[READ_END], STDIN_FILENO);
	dup2(t->fd1[WRITE_END], STDOUT_FILENO);
	check_builtins(t);
	free_matrix(s1);
	free_matrix(s2);
}
