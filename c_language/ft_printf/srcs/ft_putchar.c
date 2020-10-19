#include "../includes/ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
	g_print_len++;
}
