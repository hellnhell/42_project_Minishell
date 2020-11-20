/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 18:13:40 by emartin-          #+#    #+#             */
/*   Updated: 2020/11/20 17:14:12 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_signal_c1(int sign)
{
	if (sign == SIGINT)
        ft_printf("\n");
}

void	ft_signal_c(int sign)
{
	if (sign == SIGINT)
    {
        ft_printf("\n");
		ft_putstr_fd(PROMPT, 1);
    }
}

void	ft_signal_d(int sign)
{
	if (sign == 1)
	{
       	ft_printf("\n");
       	ft_putstr_fd(PROMPT, 1);
        ft_printf("exit\n");
        exit(0);
	}
}

void	ft_signal_quit(int sign)
{
	if (sign == SIGQUIT)
        ft_printf("QUIT: 3\n");
}