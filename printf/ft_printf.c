/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 13:09:51 by isfernan          #+#    #+#             */
/*   Updated: 2020/02/25 18:03:23 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_data	*data;
	int		i;
	va_list	lista;

	va_start(lista, format);
	if (!format || (ft_strlen(format) == 1 && *format == '%'))
		return (0);
	data = malloc(sizeof(t_data));
	data->printed = 0;
	szeros(data);
	i = 0;
	while (format[i] && i != (-1))
	{
		while (format[i] && format[i] != '%')
			putchr_add(i++, format, data);
		if (format[i] == '%')
		{
			i = read_flags(++i, format, data, lista);
			call_spe(data, lista);
		}
		szeros(data);
		i = (i == 0 ? -1 : i);
	}
	free(data);
	return (data->printed);
}

void	szeros(t_data *data)
{
	data->fm = 0;
	data->f0 = 0;
	data->width = 0;
	data->pre = -1;
	data->spe = '0';
}

int		read_flags(int i, const char *format, t_data *data, va_list lista)
{
	if (format[i] == '0')
	{
		data->f0 = 1;
		i++;
	}
	if (*(format + i) == '-')
		data->fm++;
	if (*(format + i + data->fm) == '*')
	{
		data->width = va_arg(lista, int);
		i = i + 1 + data->fm;
		if (data->width < 0)
		{
			data->width = data->width * (-1);
			data->fm++;
		}
	}
	else
		i = read_flags_else(i, format, data);
	return (read_flags_2(i, format, data, lista));
}

int		read_flags_else(int i, const char *format, t_data *data)
{
	int nb;

	while (*(format + i) == '0')
		i++;
	nb = ft_atoi(format + i);
	if (nb < 0)
	{
		while (*(format + i + 1) == '0')
			i++;
		data->width = nb * (-1);
	}
	else
		data->width = nb;
	return (i + count_nb(nb, 10) + data->fm);
}

int		read_flags_2(int i, const char *format, t_data *data, va_list lista)
{
	int nb;

	if (format[i] == '.')
	{
		if (*(format + i + 1) == '*')
		{
			if ((data->pre = va_arg(lista, int)) < 0)
				data->pre = -1;
			i = i + 2;
		}
		else
		{
			while (*(format + i + 1) == '0')
				i++;
			nb = ft_atoi(format + ++i);
			data->pre = nb;
			i = i + count_nb(nb, 10);
			if (data->pre == 0 && format[i] == '0')
				i++;
		}
	}
	data->spe = format[i];
	if (!data->spe)
		i = -1;
	return (++i);
}
