/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofloren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 02:04:58 by nofloren          #+#    #+#             */
/*   Updated: 2020/07/02 19:41:38 by nofloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;

	g_print_len = 0;
	va_start(ap, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (ft_specifier(str, &i, ap) == 0)
			{
				va_end(ap);
				return (g_print_len);
			}
			i++;
		}
		else
			ft_putchar(str[i++]);
	}
	va_end(ap);
	return (g_print_len);
}
