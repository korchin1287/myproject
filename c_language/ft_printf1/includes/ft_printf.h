/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofloren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 18:53:37 by nofloren          #+#    #+#             */
/*   Updated: 2020/07/02 19:45:17 by nofloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

int		g_print_len;

int		ft_printf(const char *str, ...);
int		ft_specifier(const char *str, int *i, va_list ap);
int		ft_check_specifier(char c);
int		*ft_create_mod(int *mod, const char *str, int *i, va_list ap);
int		ft_is_specifier(char c);
int		ft_atoi(const char *str);
void	ft_putchar(char c);
void	ft_putstr(const char *str);
void	ft_printaddr(unsigned long int nb);
void	ft_printx(int n, char c);
void	ft_printux(unsigned long long int n, char c);
void	ft_putnbr(int nb);
void	ft_putunbr(unsigned int nb);
void	ft_putulnbr(unsigned long int nb);
void	ft_print_let(int *mod, char c);
void	ft_print_d(int *mod, va_list ap);
void	ft_print_u(int *mod, va_list ap);
void	ft_print_h(int *mod, va_list ap, char c);
void	ft_print_s(int *mod, va_list ap);
void	ft_print_c(int *mod, va_list ap);
size_t	ft_strlen(const char *str);

#endif
