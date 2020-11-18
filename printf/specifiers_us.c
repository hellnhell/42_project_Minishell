/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers_us.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:46:27 by isfernan          #+#    #+#             */
/*   Updated: 2020/11/18 20:18:26 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_uint(t_data *data, va_list lista)
{
	unsigned int	nb;
	int				z;
	int				s;

	if ((nb = va_arg(lista, unsigned int)) == 0 && data->pre == 0)
		return (putchr_add_nb(' ', data->width, data));
	if (data->pre != -1 && data->width)
		return (ft_int_both(data, nb));
	z = (data->pre > -1 ? data->pre - count_nbuu(nb, 10) : 0);
	s = data->width - (z + count_nbuu(nb, 10));
	if (data->fm == 0)
	{
		if (!data->f0)
			putchr_add_nb(' ', s, data);
		if (nb < 0)
			putsmpl('-', data);
		if (nb < 0 && data->pre > count_nb(nb, 10))
			z++;
		putchr_add_nb('0', z, data);
		if (data->f0)
			putchr_add_nb('0', s, data);
		put_nbru(nb, data);
	}
	else
		ft_uint_else(nb, z, s, data);
}

void	ft_uint_else(int nb, int z, int s, t_data *data)
{
	if (nb < 0)
		putsmpl('-', data);
	putchr_add_nb('0', z, data);
	put_nbru(nb, data);
	putchr_add_nb(' ', s, data);
}

void	ft_str(t_data *data, va_list lista)
{
	char	*str;
	int		i;

	i = -1;
	str = va_arg(lista, char *);
	if (!str)
		return (ft_str_null(data));
	if (data->pre == -1 || data->pre > (int)ft_strlen(str))
		data->pre = ft_strlen(str);
	if (!data->fm)
	{
		while (++i < (data->width - data->pre))
			putsmpl(' ', data);
		i = -1;
		while (++i < data->pre)
			putchr_add(i, str, data);
	}
	else
	{
		while (++i < data->pre)
			putchr_add(i, str, data);
		i = -1;
		while (++i < (data->width - data->pre))
			putsmpl(' ', data);
	}
}

void	ft_str_null(t_data *data)
{
	int		i;

	i = ft_min_2(data->pre, 6);
	if (data->fm == 0)
	{
		while (data->width - i > 0)
		{
			putsmpl(' ', data);
			i++;
		}
		put_str_len("(null)", ft_min_2(data->pre, 6), data);
	}
	else
	{
		put_str_len("(null)", ft_min_2(data->pre, 6), data);
		while (data->width - i > 0)
		{
			putsmpl(' ', data);
			i++;
		}
	}
}
