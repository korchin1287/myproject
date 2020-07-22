/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofloren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 16:02:57 by nofloren          #+#    #+#             */
/*   Updated: 2020/06/26 17:28:18 by nofloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr(int n)
{
	int i;

	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
	else
	{
		i = n % 10;
		n = n / 10;
		if (n != 0)
			ft_putnbr(n);
		ft_putchar(i + '0');
	}
}

void	ft_putunbr(unsigned int nb)
{
	if (nb >= 10)
	{
		ft_putunbr(nb / 10);
		ft_putunbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

void	ft_putulnbr(unsigned long int nb)
{
	if (nb >= 10)
	{
		ft_putulnbr(nb / 10);
		ft_putulnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}
