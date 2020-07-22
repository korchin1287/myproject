/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofloren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 16:32:05 by nofloren          #+#    #+#             */
/*   Updated: 2020/07/02 17:59:32 by nofloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_help_s(int *mod, int len, char *str)
{
	int		i;

	i = -1;
	if (mod[1] == 0 || mod[0])
	{
		if (mod[0] == 0)
			while (mod[2]-- > len)
				ft_putchar(' ');
		while (++i < len)
		{
			if ((!mod[0] && !mod[1] && !mod[2] && mod[3] && !mod[4]))
				break ;
			ft_putchar(str[i]);
		}
		while (mod[0] != 0 && mod[2]-- > len)
			ft_putchar(' ');
		return ;
	}
	while (mod[2]-- > len)
		ft_putchar('0');
	while (++i < len)
		ft_putchar(str[i]);
}

void		ft_print_s(int *mod, va_list ap)
{
	char	*str;
	int		len;
	int		letters;

	str = va_arg(ap, char *);
	if (str == NULL)
	{
		if (!mod[3] || mod[4])
			str = "(null)";
		else
			str = "";
	}
	letters = ft_strlen(str);
	if (mod[4])
	{
		if (mod[4] < letters)
			len = mod[4];
		else
			len = letters;
	}
	else
		len = letters;
	if (!mod[4] && mod[3])
		len = 0;
	ft_help_s(mod, len, str);
}
