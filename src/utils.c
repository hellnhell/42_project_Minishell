/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:19:39 by isfernan          #+#    #+#             */
/*   Updated: 2020/10/29 18:28:05 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
}

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
