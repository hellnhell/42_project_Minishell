/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_global.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 19:07:33 by emartin-          #+#    #+#             */
/*   Updated: 2020/01/07 16:09:49 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_mins_off_precs_off(char *s, t_tab *tab)
{
	if (s == NULL)
	{
		ft_put_sp(tab->prec - tab->width, tab);
		tab->len--;
	}
	if (tab->zero == 1)
		ft_put_zero(tab->width - ft_strlen(s), tab);
	else if (tab->width > ft_strlen(s))
		ft_put_sp(tab->width - ft_strlen(s), tab);
	ft_putstr_fd(s, 1, tab);
}

void	ft_mins_on_precs_off(char *s, t_tab *tab)
{
	ft_putstr_fd(s, 1, tab);
	if (tab->width > ft_strlen(s))
		ft_put_sp(tab->width - ft_strlen(s), tab);
}

void	ft_mins_off_precs_on(char *s, t_tab *tab)
{
	int	i;

	i = 0;
	if (tab->prec < ft_strlen(s))
	{
		if (tab->width > tab->prec)
			ft_put_sp(tab->width - tab->prec, tab);
		while (i < tab->prec && s[i] != 0)
		{
			ft_putchar_fd(s[i], 1, tab);
			i++;
		}
	}
	else
	{
		if (tab->width >= tab->prec)
			ft_put_sp(tab->width - ft_strlen(s), tab);
		ft_putstr_fd(s, 1, tab);
	}
}

void	ft_mins_on_precs_on(char *s, t_tab *tab)
{
	int		i;

	i = 0;
	if (tab->prec < ft_strlen(s))
	{
		while (i < tab->prec && s[i] != 0)
		{
			ft_putchar_fd(s[i], 1, tab);
			i++;
		}
		if (tab->width > tab->prec)
			ft_put_sp(tab->width - tab->prec, tab);
	}
	else
	{
		ft_putstr_fd(s, 1, tab);
		if (tab->width >= tab->prec)
			ft_put_sp(tab->width - ft_strlen(s), tab);
	}
}

void	ft_putstr_global(t_tab *tab, va_list args)
{
	char	*s;

	s = va_arg(args, char *);
	if (s == NULL)
		s = "(null)";
	if (tab->minus == 0 && tab->prec_true == 0)
		ft_mins_off_precs_off(s, tab);
	if (tab->minus == 1 && tab->prec_true == 0)
		ft_mins_on_precs_off(s, tab);
	if (tab->minus == 0 && tab->prec_true == 1)
	{
		if (*s == 0)
			ft_put_sp(tab->width - ft_strlen(s), tab);
		else
			ft_mins_off_precs_on(s, tab);
	}
	if (tab->minus == 1 && tab->prec_true == 1)
		ft_mins_on_precs_on(s, tab);
}
