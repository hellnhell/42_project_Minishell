/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers_resto.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:47:50 by isfernan          #+#    #+#             */
/*   Updated: 2020/02/25 17:15:11 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hex(t_data *data, va_list lista)
{
	int				j;
	int				z;
	int				s;
	unsigned int	nb;

	if ((nb = va_arg(lista, unsigned int)) == 0 && data->pre == 0)
		return (putchr_add_nb(' ', data->width, data));
	j = count_nbuu(nb, 16);
	z = data->pre - j;
	s = (z > 0 ? data->width - j - z : data->width - j);
	if (data->fm == 0)
	{
		if (data->f0 && data->pre == -1)
			putchr_add_nb('0', s, data);
		else
			putchr_add_sz(s, z, data);
		to_base(nb, "0123456789abcdef", data);
	}
	else
	{
		putchr_add_nb('0', z, data);
		to_base(nb, "0123456789abcdef", data);
		putchr_add_nb(' ', s, data);
	}
}

void	ft_hexx(t_data *data, va_list lista)
{
	int				j;
	int				z;
	int				s;
	unsigned int	nb;

	if ((nb = va_arg(lista, unsigned int)) == 0 && data->pre == 0)
		return (putchr_add_nb(' ', data->width, data));
	j = count_nbuu(nb, 16);
	z = data->pre - j;
	s = (z > 0 ? data->width - j - z : data->width - j);
	if (data->fm == 0)
	{
		if (data->f0 && data->pre == -1)
			putchr_add_nb('0', s, data);
		else
			putchr_add_sz(s, z, data);
		to_base(nb, "0123456789ABCDEF", data);
	}
	else
	{
		putchr_add_nb('0', z, data);
		to_base(nb, "0123456789ABCDEF", data);
		putchr_add_nb(' ', s, data);
	}
}

void	ft_ptr(t_data *data, va_list lista)
{
	unsigned long		nb;
	int					s;

	nb = va_arg(lista, unsigned long);
	s = data->width - 2 - count_nbu2(nb, 16);
	if (data->pre == 0 && !nb)
		s = s + 1;
	if (data->fm == 0)
	{
		putchr_add_nb(' ', s, data);
		putsmpl('0', data);
		putsmpl('x', data);
		if (data->pre != 0)
			to_base2(nb, "0123456789abcdef", data);
	}
	else
	{
		putsmpl('0', data);
		putsmpl('x', data);
		if (data->pre != 0)
			to_base2(nb, "0123456789abcdef", data);
		putchr_add_nb(' ', s, data);
	}
}

void	ft_perc(t_data *data)
{
	int	s;

	s = data->width - 1;
	if (data->fm == 0)
	{
		if (data->f0 == 0)
			putchr_add_nb(' ', s, data);
		else
			putchr_add_nb('0', s, data);
		putsmpl('%', data);
	}
	else
	{
		putsmpl('%', data);
		if (data->f0 == 0)
			putchr_add_nb(' ', s, data);
		else
			putchr_add_nb('0', s, data);
	}
}

void	ft_char(t_data *data, va_list lista)
{
	char	c;

	c = va_arg(lista, int);
	if (data->fm)
	{
		putsmpl(c, data);
		if (data->f0 == 1)
			putchr_add_nb('0', data->width - 1, data);
		else
			putchr_add_nb(' ', data->width - 1, data);
	}
	else
	{
		if (data->f0 == 1)
			putchr_add_nb('0', data->width - 1, data);
		else
			putchr_add_nb(' ', data->width - 1, data);
		putsmpl(c, data);
	}
}
