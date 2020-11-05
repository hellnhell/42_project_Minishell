/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_global.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 12:46:31 by emartin-          #+#    #+#             */
/*   Updated: 2020/01/07 18:37:14 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_min_off_prec_off(int nbr, t_tab *tab)
{
	if (tab->zero == 1)
	{
		if (nbr < 0)
		{
			tab->len += write(1, "-", 1);
			nbr = nbr * (-1);
			tab->width--;
		}
		ft_put_zero((tab->width - ft_count_int(nbr, tab)), tab);
	}
	else
		ft_put_sp((tab->width - ft_count_int(nbr, tab)), tab);
	ft_putstr_fd(ft_itoa(nbr), 1, tab);
}

void		ft_min_on_prec_off(int nbr, t_tab *tab)
{
	ft_putstr_fd(ft_itoa(nbr), 1, tab);
	tab->count = 0;
	if (tab->width > ft_count_int(nbr, tab))
		ft_put_sp((tab->width - tab->count), tab);
}

void		ft_min_off_prec_on(int nbr, t_tab *tab)
{
	if (tab->prec >= ft_count_int(nbr, tab))
	{
		if (nbr < 0)
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
	ft_putstr_fd(ft_itoa(nbr), 1, tab);
}

void		ft_min_on_prec_on(int nbr, t_tab *tab)
{
	if (nbr < 0)
	{
		tab->len += write(1, "-", 1);
		nbr = nbr * (-1);
		tab->width--;
	}
	if (tab->prec >= ft_count_int(nbr, tab))
	{
		ft_put_zero((tab->prec - tab->count), tab);
		ft_putstr_fd(ft_itoa(nbr), 1, tab);
		ft_put_sp(tab->width - tab->prec, tab);
	}
	else
	{
		ft_putstr_fd(ft_itoa(nbr), 1, tab);
		ft_put_sp(tab->width - tab->count, tab);
	}
}

void		ft_putnbr_global(t_tab *tab, va_list args)
{
	int		nbr;

	nbr = va_arg(args, int);
	if (nbr == 0 && tab->prec_true == 1 && tab->prec == 0)
		ft_put_sp((tab->width - tab->prec), tab);
	else
	{
		if (tab->minus == 0 && tab->prec_true == 0)
			ft_min_off_prec_off(nbr, tab);
		if (tab->minus == 1 && tab->prec_true == 0)
			ft_min_on_prec_off(nbr, tab);
		if (tab->minus == 0 && tab->prec_true == 1)
			ft_min_off_prec_on(nbr, tab);
		if (tab->minus == 1 && tab->prec_true == 1)
			ft_min_on_prec_on(nbr, tab);
	}
}
