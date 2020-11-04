/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hellnhell <hellnhell@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:02:19 by isfernan          #+#    #+#             */
/*   Updated: 2020/11/04 13:14:07 by hellnhell        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cpy_env(char **env, t_tab *t)
{
	int		l;
	int		c;

	l = 0;
	while (env[l])
	{
		c = 0;
		while (env[l][c])
		{
			t->env[l][c] = env[l][c];
			c++;
		}
        t->env[l][c] = '\0';
		l++;
	}
}

void	ft_allocate_env(char **env, t_tab *t)
{
	int		l;
	int		c;

	l = 0;
	c = 0;
	while (env[l])
		l++;
	t->env = (char **)malloc(sizeof(char *) * (l + 1));
	t->env[l] = NULL;
	l = 0;
	while (env[l])
	{
		c = 0;
		while (env[l][c])
			c++;
		t->env[l] = (char *)malloc(sizeof(char) * (c + 1));
		//t->env[l][c] = '\0';
		l++;
	}
	ft_cpy_env(env, t);
	free_matrix(t->env);
}


int     ft_env(char **env)
{
	int     l;

	l = -1;
	while (env[++l])
	{
		ft_putstr_fd(env[l], 1);
		if (env[l + 1])
			ft_putchar_fd('\n', 1);
	}
	return (0);
}
