/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 18:04:38 by emartin-          #+#    #+#             */
/*   Updated: 2020/10/26 20:18:18 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		not_command_error(t_tab *t)
{
	ft_putstr_fd("zsh : command not found: ", 1);
	ft_putstr_fd(t->tokens[0], 1);
	write(1, "\n", 2);	
	return(0);
}


int		check_path(t_tab *t, char **env)
{
	int		i;
	int		j;
	char	*aux;
	char	*tmp;

	i = 0;
	//exit q hay q gestionar con errno
	printf("tokens-----%s\n", t->tokens[0]);
	if (!t->tokens[0])
		printf("errrrrrroorrrrr\n");
	while(t->path[i])
	{
		//printf("%d\n", i);
		aux = ft_strjoin_sl(t->path[i], t->tokens[0]);
		tmp = aux;
		j = execve(tmp, t->tokens, env);
		free(aux);
		i++;
	}
	if (j < 0)
		not_command_error(t);
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
