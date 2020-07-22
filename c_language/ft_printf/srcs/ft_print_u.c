/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofloren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 19:43:14 by nofloren          #+#    #+#             */
/*   Updated: 2020/07/02 17:59:06 by nofloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_count_u(unsigned int num)
{
	int				letters;

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

static void		ft_h(int *mod, int len, unsigned int num, int flag)
{
	int				letters;

	letters = ft_count_u(num);
	if (mod[3] || mod[1] == 0 || mod[0])
	{
		if (mod[0] == 0)
		{
			while (mod[2]-- > len)
				ft_putchar(' ');
		}
		while (mod[4]-- > letters)
			ft_putchar('0');
		if (!flag || (flag && !len && !num && mod[5]))
			ft_putunbr(num);
		if (mod[0] != 0)
		{
			while (mod[2]-- > len)
				ft_putchar(' ');
		}
		return ;
	}
	while (mod[2]-- > len)
		ft_putchar('0');
	if (!flag)
		ft_putunbr(num);
}

void			ft_print_u(int *mod, va_list ap)
{
	unsigned int	num;
	int				letters;
	int				len;
	int				flag;

	num = va_arg(ap, unsigned int);
	flag = 0;
	letters = ft_count_u(num);
	if (mod[4] > letters)
		len = mod[4];
	else
		len = letters;
	if (mod[3] && mod[4] == 0 && num == 0)
	{
		flag = 1;
		len = 0;
	}
	ft_h(mod, len, num, flag);
}
