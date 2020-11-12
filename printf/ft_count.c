/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 12:36:03 by emartin-          #+#    #+#             */
/*   Updated: 2020/11/11 17:55:16 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_count_int(int nbr, t_tab *tab)
{
	if (nbr <= 0)
	{
		nbr = nbr * (-1);
		tab->count++;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		tab->count++;
	}
	return (tab->count);
}

int		ft_count_hex(unsigned long nbr, t_tab *tab)
{
	if ((int)nbr < 0)
	{
		nbr = nbr * (-1);
		tab->count++;
	}
	while (nbr > 0)
	{
		nbr = nbr / 16;
		tab->count++;
	}
	return (tab->count);
}

int		ft_count_uns(unsigned int nbr, t_tab *tab)
{
	if (nbr <= 0)
	{
		nbr = nbr * (-1);
		tab->count++;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		tab->count++;
	}
	return (tab->count);
}

void	ft_initializate(t_tab *tab)
{
	tab->len = 0;
	tab->count = 0;
	tab->prec = 0;
	tab->minus = 0;
	tab->width = 0;
	tab->pp = 0;
}

void	ft_putchar_fd(char c, int fd, t_tab *tab)
{
	write(fd, &c, 1);
	tab->len++;
}
