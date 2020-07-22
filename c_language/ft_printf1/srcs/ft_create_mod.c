/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_mod.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofloren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 18:59:30 by nofloren          #+#    #+#             */
/*   Updated: 2020/07/02 19:32:04 by nofloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_is_flag(char c)
{
	if (c == '-' || c == '0' || c == '*')
		return (1);
	return (0);
}

static void		ft_create_m_h2(int *mod, const char *str, int *i, va_list ap)
{
	if (str[*i] == '*')
	{
		mod[5]++;
		if (str[*i - 1] == '.')
		{
			mod[4] = va_arg(ap, int);
			if (mod[4] < 0)
				mod[4] = 2147483647;
		}
		else
		{
			mod[2] = va_arg(ap, int);
			if (mod[2] < 0)
			{
				mod[0] = 1;
				mod[2] *= -1;
			}
		}
	}
}

static void		ft_create_m_h(int *mod, const char *str, int *i, va_list ap)
{
	if (str[*i] == '.')
	{
		mod[3]++;
		mod[4] = 0;
	}
	ft_create_m_h2(mod, str, i, ap);
	if (ft_isdigit(str[*i]))
	{
		if ((str[*i - 1] == '.'))
			mod[4] = ft_atoi(&str[*i]);
		else
			mod[2] = ft_atoi(&str[*i]);
		while (ft_isdigit(str[*i]))
			(*i)++;
		(*i)--;
	}
}

int				*ft_create_mod(int *mod, const char *str, int *i, va_list ap)
{
	int j;

	j = 0;
	while (j < 7)
		mod[j++] = 0;
	while (ft_is_flag(str[*i]) || ft_isdigit(str[*i]) || str[*i] == '.')
	{
		if (str[*i] == '-')
			mod[0]++;
		if (str[*i] == '0' && str[*i - 1] != '.')
			mod[1]++;
		if (ft_isdigit(str[*i]) || str[*i] == '.' || str[*i] == '*')
			ft_create_m_h(mod, str, i, ap);
		(*i)++;
		if (str[*i] == 'p')
			mod[6] = 1;
		if (mod[4] == 2147483647 && (str[*i] != 's'))
			mod[4] = 0;
	}
	return (mod);
}
