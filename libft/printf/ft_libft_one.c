/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:14:47 by emartin-          #+#    #+#             */
/*   Updated: 2020/01/07 18:17:03 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int		ft_size(unsigned int i)
{
	unsigned int		z;

	z = 1;
	while (i >= 10)
	{
		i = i / 10;
		z++;
	}
	return (z);
}

char			*ft_itoa(int n)
{
	unsigned int		i;
	unsigned int		j;
	unsigned int		z;
	char				*str;

	if (n < 0)
		i = (unsigned int)(n * -1);
	else
		i = (unsigned int)n;
	z = ft_size(i);
	if (!(str = (char*)malloc(sizeof(char) * z + 1 + (n < 0 ? 1 : 0))))
		return (0);
	if (n < 0 && (str[0] = '-'))
		z++;
	j = z - 1;
	while (i >= 10)
	{
		str[j--] = (char)(i % 10 + '0');
		i /= 10;
	}
	str[j] = (char)(i % 10 + '0');
	str[z] = 0;
	return (str);
}

int				ft_atoi(const char *str)
{
	int	x;
	int	neg;

	neg = 1;
	x = 0;
	while (*str && (*str == '\t' || *str == '\n' || *str == '\v' ||
	*str == '\f' || *str == ' ' || *str == '\r'))
		++str;
	if (*str == '-')
		neg = -1;
	if (*str == '+' || *str == '-')
		++str;
	while (*str && *str >= '0' && *str <= '9')
	{
		x = x * 10 + (*str - 48);
		++str;
	}
	return (x * neg);
}

int				ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
