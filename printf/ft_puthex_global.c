/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_global.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hellnhell <hellnhell@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 12:41:50 by emartin-          #+#    #+#             */
/*   Updated: 2020/11/05 21:28:06 by hellnhell        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_minx_off_precx_off(unsigned int nbr, t_tab *tab)
{
	if (tab->zero == 1)
	{
		if ((int)nbr < 0)
		{
			tab->len += write(1, "-", 1);
			nbr = nbr * (-1);
			tab->width--;
			tab->count--;
		}
		ft_put_zero(tab->width - ft_count_hex(nbr, tab), tab);
	}
	else if (nbr == 0)
	{
		ft_put_sp(--tab->width - ft_count_hex(nbr, tab), tab);
		ft_put_zero(1, tab);
	}
	else
		ft_put_sp(tab->width - ft_count_hex(nbr, tab), tab);
	ft_puthex(tab, nbr);
}

void		ft_minx_on_precx_off(unsigned int nbr, t_tab *tab)
{
	ft_puthex(tab, (nbr));
	if (nbr == 0)
	{
		ft_put_zero(1, tab);
		ft_put_sp(--tab->width - ft_count_hex(nbr, tab), tab);
	}
	else if (tab->width > ft_count_hex(nbr, tab))
		ft_put_sp((tab->width - tab->count), tab);
}

void		ft_minx_off_precx_on(unsigned int nbr, t_tab *tab)
{
	if (tab->prec >= ft_count_hex(nbr, tab))
	{
		if (nbr == 0)
			ft_put_sp(tab->width - tab->prec, tab);
		else if ((int)nbr < 0)
		{
			ft_put_sp((--tab->width - tab->prec), tab);
			tab->len += write(1, "-", 1);
			nbr = nbr * (-1);
			tab->width--;
			tab->count--;
		}
		else
			ft_put_sp((tab->width - tab->prec), tab);
		ft_put_zero(tab->prec - tab->count, tab);
	}
	else
		ft_put_sp((tab->width - tab->count), tab);
	ft_puthex(tab, (nbr));
}

void		ft_minx_on_precx_on(unsigned int nbr, t_tab *tab)
{
	if (nbr == 0)
	{
		ft_put_zero((tab->prec), tab);
		ft_put_sp(tab->width - tab->prec, tab);
	}
	else if ((int)nbr < 0)
	{
		tab->len += write(1, "-", 1);
		nbr = nbr * (-1);
		tab->width--;
	}
	else if (tab->prec >= ft_count_hex(nbr, tab) ||
	tab->zero == 1)
	{
		ft_put_zero(tab->prec - tab->count, tab);
		ft_puthex(tab, (nbr));
		ft_put_sp(tab->width - tab->prec, tab);
	}
	else
	{
		ft_puthex(tab, (nbr));
		ft_put_sp(tab->width - tab->count, tab);
	}
}

void		ft_puthex_global(t_tab *tab, va_list args)
{
	unsigned int		nbr;

	nbr = va_arg(args, unsigned int);
	if (nbr == 0 && tab->prec_true == 1 && tab->prec == 0)
		ft_put_sp((tab->width - tab->prec), tab);
	else
	{
		if (tab->minus == 0 && tab->prec_true == 0)
			ft_minx_off_precx_off(nbr, tab);
		if (tab->minus == 1 && tab->prec_true == 0)
			ft_minx_on_precx_off(nbr, tab);
		if (tab->minus == 0 && tab->prec_true == 1)
			ft_minx_off_precx_on(nbr, tab);
		if (tab->minus == 1 && tab->prec_true == 1)
			ft_minx_on_precx_on(nbr, tab);
	}
}
