/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:19:39 by isfernan          #+#    #+#             */
/*   Updated: 2020/11/06 17:41:24 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void	ft_allocate_path(t_tab *t, char **path)
{
	int		l;
	int		c;
	char	*buff;

	l = 0;
	c = 0;
	buff = malloc(1024);
	getcwd(buff, 1024);
	while (path[l])
		l++;
	t->path = (char **)malloc(sizeof(char *) * (l + 2));
	t->path[l] = NULL;
	l = 0;
	while (path[l])
	{
		c = 0;
		while (path[l][c])
			c++;
		t->path[l] = (char *)malloc(sizeof(char) * (c + 1));
		//t->env[l][c] = '\0';
		l++;
	}
	t->path[l] = (char *)malloc(sizeof(char) * (ft_strlen(buff) + 1));
	free(buff);
}

void	ft_cpy_path(t_tab *t, char **path)
{
	int		l;
	int		c;
	char	*buff;
	char	*s;

	buff = malloc(1024);
	getcwd(buff, 1024);
	l = 0;
	while (path[l])
	{
		c = 0;
		while (path[l][c])
		{
			t->path[l][c] = path[l][c];
			c++;
		}
        t->path[l][c] = '\0';
		l++;
	}
	t->path[l] = ft_strcpy(t->path[l], buff);
	free(buff);
}
