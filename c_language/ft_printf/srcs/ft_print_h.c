#include "../includes/ft_printf.h"

static int				ft_count_h(unsigned long int num)
{
	int					letters;

	letters = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		num = num / 16;
		letters++;
	}
	return (letters);
}

static void				ft_x(int *m, int l, unsigned long int n, int f)
{
	int					letters;

	letters = ft_count_h(n);
	if (m[3] || m[1] == 0 || m[0])
	{
		while (!m[0] && m[2]-- > l)
			ft_putchar(' ');
		if ((!f && m[6] && n != 0) || (f && l == 2) || (m[6] && n == 0))
			ft_putstr("0x");
		while (m[4]-- > letters)
			ft_putchar('0');
		if (!f || (!n && m[5] && f))
			ft_printux(n, 'x');
		while (m[0] && m[2]-- > l)
			ft_putchar(' ');
		return ;
	}
	if ((!f && m[6] && n != 0) || (f && l == 2))
		ft_putstr("0x");
	while (m[2]-- > l)
		ft_putchar('0');
	if (!f)
		ft_printux(n, 'x');
}

static void				ft_xx(int *mod, int len, unsigned int num, int flag)
{
	int					letters;

	letters = ft_count_h(num);
	if (mod[3] || mod[1] == 0 || mod[0])
	{
		while (!mod[0] && mod[2]-- > len)
			ft_putchar(' ');
		while (mod[4]-- > letters)
			ft_putchar('0');
		if (!flag || (!num && flag && mod[5]))
			ft_printux(num, 'X');
		while (mod[0] && mod[2]-- > len)
			ft_putchar(' ');
		return ;
	}
	while (mod[2]-- > len)
		ft_putchar('0');
	if (!flag)
		ft_printux(num, 'X');
}

static long long int	ft_get_num(char c, va_list ap)
{
	unsigned long int	num;

	if (c == 'p')
		num = va_arg(ap, unsigned long int);
	else
		num = (unsigned int)va_arg(ap, unsigned int);
	return (num);
}

void					ft_print_h(int *mod, va_list ap, char c)
{
	unsigned long int	num;
	int					len;
	int					flag;

	num = ft_get_num(c, ap);
	flag = 0;
	if (mod[4] > ft_count_h(num))
		len = mod[4];
	else
		len = ft_count_h(num);
	if (c == 'p')
		len += 2;
	if (mod[3] && mod[4] == 0 && num == 0)
	{
		flag = 1;
		if (c == 'p')
			len = 2;
		else
			len = 0;
	}
	c == 'X' ? ft_xx(mod, len, num, flag) : ft_x(mod, len, num, flag);
}
