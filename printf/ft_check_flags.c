/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 16:55:34 by emartin-          #+#    #+#             */
/*   Updated: 2020/01/07 17:58:51 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_check_minzero(t_tab *tab)
{
	while ((*(tab->str) == '0') || (*(tab->str) == '-'))
	{
		if (*(tab->str) == '0' && tab->minus == 0)
			tab->zero = 1;
		if (*(tab->str) == '-')
		{
			tab->minus = 1;
			tab->zero = 0;
		}
		tab->str++;
	}
}

void		ft_check_width(va_list args, t_tab *tab)
{
	if (*(tab->str) == '*' || (ft_isdigit(*(tab->str)) == 1))
	{
		if (*(tab->str) == '*')
		{
			tab->width = va_arg(args, int);
			if (tab->width < 0)
			{
				tab->width = tab->width * (-1);
				tab->minus = 1;
			}
			tab->str++;
		}
		if (ft_isdigit(*(tab->str)))
		{
			tab->width = ft_atoi(tab->str);
			while (ft_isdigit(*(tab->str)))
				tab->str++;
		}
	}
}

void		ft_check_pp(t_tab *tab)
{
	if (*(tab->str) == '%')
	{
		tab->pp = 1;
		if (tab->zero == 1)
		{
			ft_put_zero(tab->width - 1, tab);
			tab->len += write(1, "%", 1);
		}
		else if (tab->minus == 0)
		{
			ft_put_sp(tab->width - 1, tab);
			tab->len += write(1, "%", 1);
		}
		else
		{
			tab->len += write(1, "%", 1);
			ft_put_sp(tab->width - 1, tab);
		}
	}
	else
		tab->pp = 0;
}

void		ft_check_prec(va_list args, t_tab *tab)
{
	if (*(tab->str) == '.')
	{
		tab->prec_true = 1;
		tab->str++;
		if (*(tab->str) == '*')
		{
			tab->prec = va_arg(args, int);
			if (tab->prec < 0)
				tab->prec_true = 0;
			tab->str++;
		}
		if (ft_isdigit(*(tab->str)))
		{
			tab->prec = ft_atoi(tab->str);
			while (ft_isdigit(*(tab->str)))
				tab->str++;
		}
	}
	else
		tab->prec_true = 0;
}

void		ft_check_flags(va_list args, t_tab *tab)
{
	ft_check_minzero(tab);
	ft_check_width(args, tab);
	ft_check_pp(tab);
	ft_check_prec(args, tab);
}
