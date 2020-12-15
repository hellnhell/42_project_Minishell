/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 13:13:41 by isfernan          #+#    #+#             */
/*   Updated: 2020/11/18 20:16:55 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef	struct	s_index_char
{
	int		printed;
	int		fm;
	int		f0;
	int		width;
	int		pre;
	char	spe;
}				t_data;

int				ft_printf(const char *format, ...);
void			szeros(t_data *data);
int				read_flags(int i, const char *format, t_data *data,
va_list lista);
int				read_flags_else(int i, const char *format, t_data *data);
int				read_flags_2(int i, const char *format, t_data *data,
va_list lista);

void			call_spe(t_data *data, va_list lista);
void			ft_int(t_data *data, va_list lista);
void			ft_int_both(t_data *data, int nb);
void			ft_int_else(int nb, int z, int s, t_data *data);
void			ft_uint(t_data *data, va_list lista);
void			ft_uint_else(int nb, int z, int s, t_data *data);
void			ft_char(t_data *data, va_list lista);
void			ft_str(t_data *data, va_list lista);
void			ft_str_null(t_data *data);
void			ft_hex(t_data *data, va_list lista);
void			ft_hexx(t_data *data, va_list lista);
void			ft_ptr(t_data *data, va_list lista);
void			ft_perc(t_data *data);

void			putchr_add(int i, const char *format, t_data *data);
void			putchr_add_nb(char c, int t, t_data *data);
void			putchr_add_sz(int d, int t, t_data *data);
void			putsmpl(char c, t_data *data);
void			put_nbr(int nb, t_data *data);
void			put_nbru(unsigned int nb, t_data *data);
void			put_str(char *str, t_data *data);
void			put_str_len(char *str, int z, t_data *data);
void			put_nbr_long(long nb, t_data *data);

int				ft_atoi(const char *str);
size_t			ft_strlen(const char *s);
void			*ft_memcpy(void *dst, const void *src, size_t n);
int				ft_max(int a, int b);
int				ft_min(int a, int b);
int				ft_min_2(int a, int b);
int				ft_abs(int a);
void			to_base(unsigned int nb, char *base, t_data *data);
void			to_base2(unsigned long nb, char *base, t_data *data);
int				count_nb(int nb, int j);
int				count_nbu(unsigned int nb, int j);
int				count_nbuu(unsigned int nb, int j);
int				count_nbu2(unsigned long nb, int j);
int				count_nb_z(int nb, int j);
int				count_nb_z2(int nb, int j);

#endif
