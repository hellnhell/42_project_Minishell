/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:47:03 by emartin-          #+#    #+#             */
/*   Updated: 2020/11/30 20:46:40 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_pipes(t_tab *t, char **env)
{
	int		status;
	pid_t	pid;

	if (pipe(t->fd1) == 0)
	{
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
			t->status = (status / 256);
			close(t->fd1[WRITE_END]);
			dup2(t->fd1[READ_END], STDIN_FILENO);
			close(t->fd1[READ_END]);
		}
	}
	else
		exit(-1);
}

void	ft_redi_greater(t_tab *t, char **env, Node *iterator)
{
	char	**str;
	int		fd;

	str = ft_split_list(iterator->element, ' ', t);
	fd = open(str[0], O_WRONLY | O_TRUNC | O_CREAT, 0640);
	dup2(fd, STDOUT_FILENO);
	check_builtins(t, env);
	reset_stdout(t);
	dup2(fd, STDIN_FILENO);
	free_matrix(str);
}

/*void		ft_redi_greater(t_tab *t, char **env, Node *iterator)
{
	int		status;
	pid_t	pid;
	char	**str;

	str = ft_split_list(iterator->element, ' ', t);
	if (pipe(t->fd1) == 0)
	{
		t->fd1[WRITE_END] = open(str[0], O_WRONLY | O_TRUNC | O_CREAT, 0640);
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
			t->status = (status / 256);
			close(t->fd1[WRITE_END]);
			dup2(t->fd1[READ_END], STDIN_FILENO);
			close(t->fd1[READ_END]);
		}
		free_matrix(str);
		system("leaks minishell");
	}
	else
	{
		free_matrix(str);
		exit(-1);
	}
}*/

void	ft_redi_less(t_tab *t, char **env, Node *iterator)
{
	char	**str;

	str = ft_split_list(iterator->element, ' ', t);
	if (pipe(t->fd1) == 0)
	{
		t->fd1[READ_END] = open(str[0], O_RDONLY);
		if (t->fd1[READ_END] == -1)
		{
			ft_printf("bash: %s: No such file or directory\n", str[0]);
			exit(1);
		}
		dup2(t->fd1[READ_END], STDIN_FILENO);
		check_builtins(t, env);
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


/*void		ft_redi_less(t_tab *t, char **env, Node *iterator)
{
	int		status;
	pid_t	pid;
	char	**str;

	str = ft_split_list(iterator->element, ' ', t);
	if (pipe(t->fd1) == 0)
	{
		t->fd1[READ_END] = open(str[0], O_RDONLY);
		pid = fork();
		if (pid == 0)
		{
			if (t->fd1[READ_END] == -1)
			{
				ft_printf("bash: %s: No such file or directory\n", str[0]);
				exit(1);
			}
			dup2(t->fd1[READ_END], STDIN_FILENO);
			check_builtins(t, env);
			exit(0);
		}
		else if (pid > 0)
		{
			waitpid(pid, &status, 0);
			t->status = (status / 256);
			close(t->fd1[WRITE_END]);
			close(t->fd1[READ_END]);
		}
		free_matrix(str);
	}
	else
	{
		free_matrix(str);
		exit(-1);
	}
}*/

void		ft_redi_double(t_tab *t, char **env, Node *iterator)
{
	char	**str;
	int		fd;

	str = ft_split_list(iterator->element, ' ', t);
	fd = open(str[0], O_WRONLY | O_APPEND | O_CREAT, 0640);
	dup2(fd, STDOUT_FILENO);
	check_builtins(t, env);
	reset_stdout(t);
	dup2(fd, STDIN_FILENO);
	free_matrix(str);
}



/*void		ft_redi_double(t_tab *t, char **env, Node *iterator)
{
	int		status;
	pid_t	pid;
	char	**str;
	char	**s;

	str = ft_split_list(iterator->element, ' ', t);
	if (pipe(t->fd1) == 0)
	{
		t->fd1[WRITE_END] = open(str[0], O_WRONLY | O_APPEND | O_CREAT, 0640);
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
			t->status = (status / 256);
			close(t->fd1[WRITE_END]);
			dup2(t->fd1[READ_END], STDIN_FILENO);
			close(t->fd1[READ_END]);
			free_matrix(str);
		}
	}
	else
	{
		free_matrix(str);
		exit(-1);
	}
}*/

void		ft_redi_pipe(t_tab *t, char **env, Node *iterator)
{
	int		status;
	pid_t	pid;
	char	**str;

	str = ft_split_list(iterator->element, ' ', t);
	if (pipe(t->fd1) == 0)
	{
		pid = fork();
		if (pid == 0)
		{
			t->fd1[READ_END] = open(str[0], O_RDONLY);
			if (t->fd1[READ_END] == -1)
			{
				ft_printf("bash: %s: No such file or directory\n", str[0]);
				exit(1);
			}
			dup2(t->fd1[READ_END], STDIN_FILENO);
			dup2(t->fd1[WRITE_END], STDOUT_FILENO);
			check_builtins(t, env);
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
		free_matrix(str);
	}
	else
	{
		free_matrix(str);
		exit(-1);
	}
}

void	ft_redi_redi(t_tab *t, char **env, Node *iterator, char c)
{
	int		status;
	pid_t	pid;
	char	**s1;
	char	**s2;

	s1 = ft_split_list(iterator->element, ' ', t);
	s2 = ft_split_list(iterator->next->element, ' ', t);
	if (pipe(t->fd1) == 0)
	{
		t->fd1[READ_END] = open(s1[0], O_RDONLY);
		if (c == '>')
			t->fd1[WRITE_END] = open(s2[0], O_WRONLY | O_TRUNC | O_CREAT, 0640);
		else if (c == '-')
			t->fd1[WRITE_END] = open(s2[0], O_WRONLY | O_APPEND | O_CREAT, 0640);
		if (t->fd1[READ_END] == -1)
		{
			ft_printf("bash: %s: No such file or directory\n", s1[0]);
			t->status = 1;
			return ;
		}
		dup2(t->fd1[READ_END], STDIN_FILENO);
		dup2(t->fd1[WRITE_END], STDOUT_FILENO);
		check_builtins(t, env);
		free_matrix(s1);
		free_matrix(s2);
	}
	else
	{
		free_matrix(s1);
		free_matrix(s2);
		exit(-1);
	}
}
		/*pid = fork();
		if (pid == 0)
		{
			t->fd1[READ_END] = open(s1[0], O_RDONLY);
			if (t->fd1[READ_END] == -1)
			{
				ft_printf("bash: %s: No such file or directory\n", s1[0]);
				exit(1);
			}
			dup2(t->fd1[READ_END], STDIN_FILENO);
			dup2(t->fd1[WRITE_END], STDOUT_FILENO);
			check_builtins(t, env);
			exit(0);
		}
		else if (pid > 0)
		{
			waitpid(pid, &status, 0);
			t->status = (status / 256);
			close(t->fd1[WRITE_END]);
			dup2(t->fd1[READ_END], STDIN_FILENO);
			close(t->fd1[READ_END]);
		}*/