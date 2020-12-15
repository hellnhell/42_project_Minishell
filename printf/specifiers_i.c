/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 13:08:13 by isfernan          #+#    #+#             */
/*   Updated: 2020/02/25 16:46:52 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	call_spe(t_data *data, va_list lista)
{
	if (data->f0 == 1 && data->fm)
		data->f0 = 0;
	if (data->spe == 'i' || data->spe == 'd')
		ft_int(data, lista);
	if (data->spe == 'u')
		ft_uint(data, lista);
	if (data->spe == 'c')
		ft_char(data, lista);
	if (data->spe == 's')
		ft_str(data, lista);
	if (data->spe == 'x')
		ft_hex(data, lista);
	if (data->spe == 'X')
		ft_hexx(data, lista);
	if (data->spe == 'p')
		ft_ptr(data, lista);
	if (data->spe == '%')
		ft_perc(data);
}

void	ft_int(t_data *data, va_list lista)
{
	int		nb;
	int		z;
	int		s;

	if ((nb = va_arg(lista, int)) == 0 && data->pre == 0)
		return (putchr_add_nb(' ', data->width, data));
	if (data->pre != -1 && data->width)
		return (ft_int_both(data, nb));
	z = (data->pre > -1 ? data->pre - count_nb_z(nb, 10) : 0);
	s = data->width - (z + count_nb_z(nb, 10));
	if (data->fm == 0)
	{
		if (!data->f0)
			putchr_add_nb(' ', s, data);
		if (nb < 0)
			putsmpl('-', data);
		if (nb < 0 && data->pre > count_nb(nb, 10) && !data->f0)
			z++;
		putchr_add_nb('0', z, data);
		if (data->f0)
			putchr_add_nb('0', s, data);
		put_nbr(ft_abs(nb), data);
	}
	else
		ft_int_else(nb, z, s, data);
}

void	ft_int_else(int nb, int z, int s, t_data *data)
{
	if (nb < 0)
		putsmpl('-', data);
	putchr_add_nb('0', z, data);
	put_nbr(ft_abs(nb), data);
	putchr_add_nb(' ', s, data);
}

void	ft_int_both(t_data *data, int nb)
{
	int		j;
	int		z;
	int		s;

	z = data->pre - count_nb_z2(nb, 10);
	s = data->width - count_nb_z(nb, 10);
	s = (z > 0 ? s - z : s);
	j = (nb < 0 ? -1 : 0);
	nb = (j < 0 ? nb * (-1) : nb);
	if (data->fm == 0)
	{
		putchr_add_nb(' ', s, data);
		if (j < 0)
			putsmpl('-', data);
		putchr_add_nb('0', z, data);
		put_nbr(nb, data);
	}
	else
	{
		if (j < 0)
			putsmpl('-', data);
		putchr_add_nb('0', z, data);
		put_nbr(nb, data);
		putchr_add_nb(' ', s, data);
	}
}
