/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_puts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hellnhell <hellnhell@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:50:42 by emartin-          #+#    #+#             */
/*   Updated: 2020/11/05 21:27:44 by hellnhell        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_sp(int c, t_tab *tab)
{
	while (c-- > 0)
		ft_putchar_fd(' ', 1, tab);
}

void	ft_put_zero(int c, t_tab *tab)
{
	while (c-- > 0)
		ft_putchar_fd('0', 1, tab);
}

void	ft_puthex(t_tab *tab, unsigned long nbr)
{
	if (nbr != 0)
	{
		ft_puthex(tab, nbr / 16);
		if (*(tab->str) == 'X')
		{
			if (nbr % 16 >= 10)
				ft_putchar_fd('A' + (nbr % 16 % 10), 1, tab);
			else
				ft_putchar_fd('0' + nbr % 16, 1, tab);
		}
		else
		{
			if (nbr % 16 >= 10)
				ft_putchar_fd('a' + (nbr % 16 % 10), 1, tab);
			else
				ft_putchar_fd('0' + nbr % 16, 1, tab);
		}
	}
}

void	ft_putstr_fd(char *s, int fd, t_tab *tab)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			ft_putchar_fd(s[i], fd, tab);
			i++;
		}
	}
}

void	ft_putnbr_fd(unsigned int nb, int fd, t_tab *tab)
{
	unsigned int	nbr;

	if ((int)nb < 0)
	{
		ft_putchar_fd('-', fd, tab);
		nbr = (unsigned int)(nb * -1);
	}
	else
		nbr = (unsigned int)nb;
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10, fd, tab);
	ft_putchar_fd((char)(nbr % 10 + 48), fd, tab);
}
