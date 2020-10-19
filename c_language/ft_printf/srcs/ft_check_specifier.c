#include "../includes/ft_printf.h"

int	ft_check_specifier(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' ||
			c == 'u' || c == 'x' || c == 'X')
		return (1);
	return (0);
}
