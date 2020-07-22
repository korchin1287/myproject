/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printaddr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofloren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 15:46:47 by nofloren          #+#    #+#             */
/*   Updated: 2020/07/02 17:57:17 by nofloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printaddr(unsigned long int nb)
{
	char			*base;

	base = "0123456789abcdef";
	if (nb >= 16)
	{
		ft_printaddr(nb / 16);
		ft_printaddr(nb % 16);
	}
	else
		ft_putchar(base[nb]);
}

void	ft_printx(int nb, char c)
{
	unsigned int	n;
	char			*base_x;
	char			*base_xx;

	base_x = "0123456789abcdef";
	base_xx = "0123456789ABCDEF";
	n = nb;
	if (n >= 16)
	{
		ft_printx(n / 16, c);
		ft_printx(n % 16, c);
	}
	else
	{
		if (c == 'x')
			ft_putchar(base_x[n]);
		else
			ft_putchar(base_xx[n]);
	}
}

void	ft_printux(unsigned long long int nb, char c)
{
	char			*base_x;
	char			*base_xx;

	base_x = "0123456789abcdef";
	base_xx = "0123456789ABCDEF";
	if (nb >= 16)
	{
		ft_printux(nb / 16, c);
		ft_printux(nb % 16, c);
	}
	else
	{
		if (c == 'x')
			ft_putchar(base_x[nb]);
		else
			ft_putchar(base_xx[nb]);
	}
}
