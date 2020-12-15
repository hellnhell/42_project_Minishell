/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putchar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 13:32:30 by isfernan          #+#    #+#             */
/*   Updated: 2020/02/25 16:58:59 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putchr_add(int i, const char *format, t_data *data)
{
	write(1, &format[i], 1);
	data->printed++;
}

void	putchr_add_nb(char c, int t, t_data *data)
{
	int i;

	i = -1;
	while (++i < t)
	{
		write(1, &c, 1);
		data->printed++;
	}
}

void	putchr_add_sz(int d, int t, t_data *data)
{
	int i;

	i = -1;
	while (++i < d)
	{
		write(1, " ", 1);
		data->printed++;
	}
	i = -1;
	while (++i < t)
	{
		write(1, "0", 1);
		data->printed++;
	}
}

void	putsmpl(char c, t_data *data)
{
	write(1, &c, 1);
	data->printed++;
}

void	put_nbr(int nb, t_data *data)
{
	unsigned int	l;
	long long int	i;
	char			z;

	i = 1;
	if (nb == -2147483648)
		return (put_str("2147483648", data));
	if (nb == 0)
	{
		putsmpl('0', data);
		return ;
	}
	l = ft_abs(nb);
	if (nb < 0)
		putsmpl('-', data);
	while (l / i)
		i = i * 10;
	while (i / 10)
	{
		z = (l % i) / (i / 10) + '0';
		i = i / 10;
		putsmpl(z, data);
	}
}
