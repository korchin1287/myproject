/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofloren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 18:48:46 by nofloren          #+#    #+#             */
/*   Updated: 2020/07/02 17:00:23 by nofloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int			ft_count_d(int num)
{
	int letters;

	letters = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		num = num / 10;
		letters++;
	}
	return (letters);
}

static void			ft_s(int *mod, int len, int num, int flag)
{
	int		unum;
	int		letters;

	letters = ft_count_d(num);
	if (mod[0] == 0)
	{
		while (mod[2]-- > len)
			ft_putchar(' ');
	}
	if (num < 0 && num != -2147483648)
		ft_putchar('-');
	while (mod[4]-- > letters)
		ft_putchar('0');
	if (num < 0)
		unum = num * (-1);
	else
		unum = num;
	if (!flag || (flag && !len && !num && mod[5]))
		ft_putnbr(unum);
	if (mod[0] != 0)
	{
		while (mod[2]-- > len)
			ft_putchar(' ');
	}
}

static void			ft_z(int *mod, int len, int num, int flag)
{
	int unum;

	if (num < 0)
		ft_putchar('-');
	while (mod[2]-- > len)
		ft_putchar('0');
	if (num < 0)
		unum = num * (-1);
	else
		unum = num;
	if (!flag)
		ft_putnbr(unum);
}

void				ft_print_d(int *mod, va_list ap)
{
	int		num;
	int		letters;
	int		len;
	int		flag;

	num = va_arg(ap, int);
	flag = 0;
	letters = ft_count_d(num);
	if (mod[4] > letters)
		len = mod[4];
	else
		len = letters;
	if (num < 0)
		len++;
	if (mod[3] && mod[4] == 0 && num == 0)
	{
		flag = 1;
		len = 0;
	}
	if (mod[3] || mod[1] == 0 || mod[0])
		ft_s(mod, len, num, flag);
	else
		ft_z(mod, len, num, flag);
}
