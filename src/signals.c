/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 18:13:40 by emartin-          #+#    #+#             */
/*   Updated: 2020/11/19 20:14:26 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_signal_d(int sign)
{
	if (sign == SIGHUP)
    {
		ft_printf("exit\n");
		exit(0);
	}
}

void	ft_signal_c(int sign)
{
	if (sign == SIGINT)
        ft_printf("\n");
}

void	ft_signals(int sign)
{
	if (sign == SIGINT)
    {
        ft_printf("\n");
		ft_putstr_fd(PROMPT, 1);
    }
}

void	ft_signal_d1(int sign)
{

}