/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofloren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 18:58:55 by nofloren          #+#    #+#             */
/*   Updated: 2020/07/02 19:30:39 by nofloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_print_specifier_help(const char c, va_list ap)
{
	char	*str1;

	if (c == 'c')
		ft_putchar((char)va_arg(ap, int));
	else if (c == 's')
	{
		str1 = va_arg(ap, char *);
		if (str1 == NULL)
			ft_putstr("(null)");
		else
			ft_putstr(str1);
	}
	else if (c == 'p')
	{
		ft_putstr("0x");
		ft_printaddr(va_arg(ap, unsigned long int));
	}
}

static void		ft_print_specifier(const char c, va_list ap)
{
	if (c == 'c' || c == 's' || c == 'p')
		ft_print_specifier_help(c, ap);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(ap, int));
	else if (c == 'u')
		ft_putunbr(va_arg(ap, unsigned int));
	else if (c == 'x' || c == 'X')
		ft_printx(va_arg(ap, int), c);
}

static int		ft_check_mod(int *mod)
{
	int i;

	i = 0;
	while (i < 7)
	{
		if (mod[i] != 0)
			return (1);
		i++;
	}
	return (0);
}

static void		ft_print_mod_specifier(int *mod, char c, va_list ap)
{
	if (c == 'd' || c == 'i')
		ft_print_d(mod, ap);
	else if (c == 'u')
		ft_print_u(mod, ap);
	else if (c == 'x' || c == 'X' || c == 'p')
		ft_print_h(mod, ap, c);
	else if (c == 's')
		ft_print_s(mod, ap);
	else if (c == 'c')
		ft_print_c(mod, ap);
}

int				ft_specifier(const char *str, int *i, va_list ap)
{
	int	mod[7];
	int	check_mod;

	if (ft_check_specifier(str[*i]))
	{
		ft_print_specifier(str[*i], ap);
		return (1);
	}
	ft_create_mod(mod, str, i, ap);
	check_mod = ft_check_mod(mod);
	if (!check_mod || !ft_check_specifier(str[*i]))
	{
		if (!str[*i])
			return (0);
		if (!check_mod)
		{
			ft_putchar(str[*i]);
			return (1);
		}
		ft_print_let(mod, str[*i]);
		return (1);
	}
	ft_print_mod_specifier(mod, str[*i], ap);
	return (1);
}
