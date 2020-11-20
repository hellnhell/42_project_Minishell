/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:13:54 by emartin-          #+#    #+#             */
/*   Updated: 2020/11/20 18:13:03 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void		ft_exit_args(char **args, int j)//PROBAR A METER NUESTRO PRINTF
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (ft_strncmp(args[0], "-", 1) == 0)
		i++;
	while (args[0][i])
	{
		if (ft_isdigit(args[0][i]) != 1)
		{
			ft_putstr_fd("bash: exit:  ", 1);
			ft_putstr_fd(args[0], 1);
			ft_putstr_fd(": numeric argument required\n", 1);
			exit(255);
		}
		i++;
	}
	while (args[k])
	{
		if (++k > 1)
		{
			ft_putstr_fd("bash: exit: too many arguments", 1);
			exit(1);
		}
	}
	exit(j);
}

int			ft_exit(char **args, t_tab *t)
{
	int		j;

	ft_putstr_fd("exit\n", 1);
	if (args[0])
	{
		j = ft_atoi(args[0]);
		ft_exit_args(args, j);
	}
	else
	{
		system("leaks minishell");
		exit(t->status);
	}
	return (0);
}
