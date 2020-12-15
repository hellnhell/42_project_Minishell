/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:13:54 by emartin-          #+#    #+#             */
/*   Updated: 2020/12/09 17:42:15 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void		ft_exit_args(char **args, int j)
{
	int			i;
	int			k;

	i = 0;
	k = 0;
	if (ft_strncmp(args[0], "-", 1) == 0)
		i++;
	while (args[0][i])
	{
		if (ft_isdigit(args[0][i]) != 1)
		{
			ft_printf("msh: exit: %s : numeric argument required\n", args[0]);
			exit(255);
		}
		i++;
	}
	while (args[k])
	{
		if (++k > 1)
		{
			ft_printf("msh: exit: too many arguments\n");
			exit(1);
		}
	}
	exit(j);
}

int				ft_exit(char **args, t_tab *t)
{
	int			j;

	ft_printf("👋 👋 👋\n");
	if (args[0])
	{
		j = ft_atoi(args[0]);
		ft_exit_args(args, j);
	}
	else
		exit(t->status);
	return (0);
}
