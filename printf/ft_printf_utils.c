/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 15:19:40 by isfernan          #+#    #+#             */
/*   Updated: 2020/11/18 20:17:47 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi(const char *str)
{
	int neg;
	int i;
	int rtrn;

	i = 0;
	rtrn = 0;
	neg = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
			str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg++;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		rtrn = (rtrn * 10) + (str[i] - '0');
		i++;
	}
	if (neg % 2 == 1)
		rtrn = rtrn * (-1);
	return (rtrn);
}

size_t		ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*src_cast;
	char	*dst_cast;
	size_t	i;

	i = 0;
	if (!n || dst == src)
		return (dst);
	src_cast = (char *)src;
	dst_cast = (char *)dst;
	while (i < n)
	{
		dst_cast[i] = src_cast[i];
		i++;
	}
	return (dst);
}

int		ft_max(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}

int		ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
