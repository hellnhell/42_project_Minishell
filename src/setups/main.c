/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 18:29:03 by hellnhell         #+#    #+#             */
/*   Updated: 2020/12/15 17:38:05 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		free_matrix(char **matrix)
{
	int		i;

	i = 0;
	while (matrix[i])
		i++;
	i--;
	while (i >= 0)
		free(matrix[i--]);
	free(matrix);
}

char		*read_line(t_tab *t)
{
	if (!get_next_line(0, &t->line))
	{
		ft_signal_d(1);
		free(t->line);
	}
	return (t->line);
}

void		initt(t_tab *t)
{
	t->line = NULL;
	t->path = NULL;
	t->status = 0;
}

int			main(int argc, char **argv, char **env)
{
	t_tab	*t;
	t_lista	*lst;

	lst = NULL;
	(void)argc;
	(void)argv;
	if (!(t = malloc(sizeof(t_tab))))
		return (1);
	initt(t);
	ft_allocate_env(env, t);
	ft_minishell(t, lst);
}
