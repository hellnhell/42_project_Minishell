/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_global.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 15:50:02 by emartin-          #+#    #+#             */
/*   Updated: 2020/01/03 16:44:20 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_global(t_tab *tab, va_list args)
{
	char	c;

	c = (char)va_arg(args, int);
	if (tab->width && tab->minus == 0)
		ft_put_sp(tab->width - 1, tab);
	ft_putchar_fd(c, 1, tab);
	if (tab->minus == 1)
		ft_put_sp(tab->width - 1, tab);
}
