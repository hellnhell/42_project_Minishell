/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpoint_global.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 11:12:17 by emartin-          #+#    #+#             */
/*   Updated: 2020/01/07 18:32:20 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_minp_off_precp_off(unsigned long nbr, t_tab *tab)
{
	if (nbr == 0)
	{
		ft_put_sp(tab->width - 3, tab);
		tab->len += write(1, "0x", 2);
		ft_put_zero(1, tab);
	}
	else
	{
		tab->count = 0;
		if (tab->width > ft_count_hex(nbr, tab))
			ft_put_sp(--tab->width - (tab->count + 1), tab);
		tab->len += write(1, "0x", 2);
		ft_puthex(tab, nbr);
	}
}

void	ft_minp_on_precp_off(unsigned long nbr, t_tab *tab)
{
	tab->len += write(1, "0x", 2);
	ft_puthex(tab, nbr);
	tab->count = 0;
	if (tab->width > ft_count_hex(nbr, tab))
		ft_put_sp(--tab->width - (tab->count + 1), tab);
}

void	ft_minp_off_precp_on(unsigned long nbr, t_tab *tab)
{
	if (tab->prec >= ft_count_hex(nbr, tab))
	{
		ft_put_sp(tab->width - tab->prec - 2, tab);
		tab->len += write(1, "0x", 2);
		ft_put_zero(tab->prec - tab->count, tab);
	}
	else
	{
		ft_put_sp(tab->width - (tab->count + 2), tab);
		tab->len += write(1, "0x", 2);
	}
	ft_puthex(tab, nbr);
}

void	ft_minp_on_precp_on(unsigned long nbr, t_tab *tab)
{
	if (tab->prec >= ft_count_hex(nbr, tab))
	{
		tab->len += write(1, "0x", 2);
		ft_put_zero(tab->prec - tab->count, tab);
		ft_puthex(tab, nbr);
		ft_put_sp(tab->width - tab->prec - 2, tab);
	}
	else
	{
		tab->len += write(1, "0x", 2);
		ft_puthex(tab, nbr);
		ft_put_sp(tab->width - (tab->count + 2), tab);
	}
}

void	ft_putpoint_global(t_tab *tab, va_list args)
{
	unsigned long nbr;

	nbr = va_arg(args, unsigned long);
	if (tab->minus == 0 && tab->prec_true == 0)
		ft_minp_off_precp_off(nbr, tab);
	if (tab->minus == 1 && tab->prec_true == 0)
		ft_minp_on_precp_off(nbr, tab);
	if (tab->minus == 0 && tab->prec_true == 1)
		ft_minp_off_precp_on(nbr, tab);
	if (tab->minus == 1 && tab->prec_true == 1)
		ft_minp_on_precp_on(nbr, tab);
}
