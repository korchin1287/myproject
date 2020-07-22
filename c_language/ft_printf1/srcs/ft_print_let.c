/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_let.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofloren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 18:20:17 by nofloren          #+#    #+#             */
/*   Updated: 2020/06/29 18:51:22 by nofloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_let(int *mod, char c)
{
	if (mod[1] == 0 || mod[0])
	{
		if (mod[0] == 0)
		{
			while (mod[2]-- > 1)
				ft_putchar(' ');
		}
		ft_putchar(c);
		if (mod[0] != 0)
		{
			while (mod[2]-- > 1)
				ft_putchar(' ');
		}
		return ;
	}
	while (mod[2]-- > 1)
		ft_putchar('0');
	ft_putchar(c);
}
