/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:13:54 by emartin-          #+#    #+#             */
/*   Updated: 2020/11/04 19:20:38 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		ft_exit_args(char **args, int j)
{
	int		i;
	int		k;
	
	i = 0;
	k = 0;	
	while (args[k])
	{
		if(++k > 1)
		{
			ft_putstr_fd("bash: exit: too many arguments", 1);				
			exit(1);
		}
	}
	if(ft_strncmp(args[0], "-", 1) == 0)			
		i++;
	if (ft_isdigit(args[0][i]) == 1)
		exit(j);
	else
	{
		ft_putstr_fd("bash: exit:  ", 1);
		ft_putstr_fd(args[0], 1);
		ft_putstr_fd(": numeric argument required\n", 1);
		exit(255);
	}
}

int		ft_exit(char **args)
{
	int		j;
	
	ft_putstr_fd("11exit\n", 1);
	if (args[0])
	{
		j = ft_atoi(args[0]);
		ft_exit_args(args, j);
	}
	else
		exit(0);
	return(0);
}
