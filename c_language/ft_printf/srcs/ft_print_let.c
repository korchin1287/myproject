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
