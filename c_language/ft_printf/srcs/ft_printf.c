#include "../includes/ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;

	g_print_len = 0;
	va_start(ap, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (ft_specifier(str, &i, ap) == 0)
			{
				va_end(ap);
				return (g_print_len);
			}
			i++;
		}
		else
			ft_putchar(str[i++]);
	}
	va_end(ap);
	return (g_print_len);
}
