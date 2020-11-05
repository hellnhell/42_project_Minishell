/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned_global.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hellnhell <hellnhell@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:35:30 by emartin-          #+#    #+#             */
/*   Updated: 2020/11/05 21:26:14 by hellnhell        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_minu_off_precu_off(unsigned int nbr, t_tab *tab)
{
	if (tab->zero == 1)
	{
		if ((int)nbr < 0)
		{
			tab->len += write(1, "-", 1);
			nbr = nbr * (-1);
			tab->width--;
		}
		ft_put_zero((tab->width - ft_count_uns(nbr, tab)), tab);
	}
	else if (tab->width)
		ft_put_sp((tab->width - ft_count_uns(nbr, tab)), tab);
	ft_putnbr_fd(nbr, 1, tab);
}

void		ft_minu_on_precu_off(unsigned int nbr, t_tab *tab)
{
	ft_putnbr_fd(nbr, 1, tab);
	if (tab->width > ft_count_int(nbr, tab))
		ft_put_sp((tab->width - tab->count), tab);
}

void		ft_minu_off_precu_on(unsigned int nbr, t_tab *tab)
{
	if (tab->prec >= ft_count_int(nbr, tab))
	{
		if ((int)nbr < 0)
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
	ft_putnbr_fd(nbr, 1, tab);
}

void		ft_minu_on_precu_on(unsigned int nbr, t_tab *tab)
{
	if ((int)nbr < 0)
	{
		tab->len += write(1, "-", 1);
		nbr = nbr * (-1);
		tab->width--;
	}
	if (tab->prec >= ft_count_int(nbr, tab))
	{
		ft_put_zero((tab->prec - tab->count), tab);
		ft_putnbr_fd(nbr, 1, tab);
		ft_put_sp(tab->width - tab->prec, tab);
	}
	else
	{
		ft_putnbr_fd(nbr, 1, tab);
		ft_put_sp(tab->width - tab->count, tab);
	}
}

void		ft_putunsigned_global(t_tab *tab, va_list args)
{
	unsigned int	nbr;

	nbr = va_arg(args, unsigned int);
	if (nbr == 0 && tab->prec_true == 1 && tab->prec == 0)
		ft_put_sp((tab->width - tab->prec), tab);
	else
	{
		if (tab->minus == 0 && tab->prec_true == 0)
			ft_minu_off_precu_off(nbr, tab);
		if (tab->minus == 1 && tab->prec_true == 0)
			ft_minu_on_precu_off(nbr, tab);
		if (tab->minus == 0 && tab->prec_true == 1)
			ft_minu_off_precu_on(nbr, tab);
		if (tab->minus == 1 && tab->prec_true == 1)
			ft_minu_on_precu_on(nbr, tab);
	}
}
