/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 13:48:37 by emartin-          #+#    #+#             */
/*   Updated: 2020/11/11 17:50:31 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

typedef struct	s_tab
{	
	char	*str;
	int		len;
	int		minus;
	int		zero;
	int		prec;
	int		prec_true;
	int		width;
	int		count;
	int		pp;
}				t_tab;

void			ft_putchar_fd(char c, int fd, t_tab *tab);
void			ft_putstr_fd(char *s, int fd, t_tab *tab);
void			ft_putnbr_fd(unsigned int nb, int fd, t_tab *tab);
int				ft_strlen(const char *s);
char			*ft_itoa(int n);
int				ft_atoi(const char *str);
void			ft_check_flags(va_list args, t_tab *tab);
int				ft_isdigit(int c);
void			ft_check_minzero(t_tab *tab);
void			ft_check_prec(va_list args, t_tab *tab);
void			ft_check_width(va_list args, t_tab *tab);
int				ft_count_int(int nbr, t_tab *tab);
int				ft_count_hex(unsigned long nbr, t_tab *tab);
int				ft_count_uns(unsigned int nbr, t_tab *tab);
void			ft_write_cases(t_tab *tab, va_list args);
void			ft_putnbr_global(t_tab *tab, va_list args);
void			ft_putstr_global(t_tab *tab, va_list args);
void			ft_putchar_global(t_tab *tab, va_list args);
void			ft_puthex_global(t_tab *tab, va_list args);
void			ft_putpoint_global(t_tab *tab, va_list args);
void			ft_putunsigned_global(t_tab *tab, va_list args);
void			ft_put_sp(int c, t_tab *tab);
void			ft_put_zero(int c, t_tab *tab);
void			ft_puthex(t_tab *tab, unsigned long nbr);
void			ft_initializate(t_tab *tab);
void			ft_min_off_prec_off(int nbr, t_tab *tab);
void			ft_min_on_prec_off(int nbr, t_tab *tab);
void			ft_min_off_prec_on(int nbr, t_tab *tab);
void			ft_min_on_prec_on(int nbr, t_tab *tab);
void			ft_mins_on_precs_on(char *s, t_tab *tab);
void			ft_mins_off_precs_on(char *s, t_tab *tab);
void			ft_mins_on_precs_off(char *s, t_tab *tab);
void			ft_mins_off_precs_off(char *s, t_tab *tab);
void			ft_minx_on_precx_on(unsigned int nbr, t_tab *tab);
void			ft_minx_off_precx_on(unsigned int nbr, t_tab *tab);
void			ft_minx_on_precx_off(unsigned int nbr, t_tab *tab);
void			ft_minx_off_precx_off(unsigned int nbr, t_tab *tab);
void			ft_minp_off_precp_off(unsigned long nbr, t_tab *tab);
void			ft_minpu_off_precpu_off(unsigned int nbr, t_tab *tab);
void			ft_minpu_off_precpu_off(unsigned int nbr, t_tab *tab);
void			ft_minpu_off_precpu_off(unsigned int nbr, t_tab *tab);
void			ft_minpu_off_precpu_off(unsigned int nbr, t_tab *tab);

#endif
