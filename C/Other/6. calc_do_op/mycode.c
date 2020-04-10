#include "ft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_proga(char **argv)
{
	int i;
	int s1;
	int s2;

	i = 0;
	s1 = ft_atoi(argv[1]);
	s2 = ft_atoi(argv[3]);
	if (argv[2][0] == '+')
		return (s1 + s2);
	else if (argv[2][0] == '-')
		return (s1 - s2);
	else if (argv[2][0] == '*')
		return (s1 * s2);
	else if (argv[2][0] == '/')
		return (s1 / s2);
	else if (argv[2][0] == '%')
		return (s1 % s2);
	else
	{
		ft_putchar('\n');
		return (0);
	}
}

int		main(int argc, char **argv)
{
	if (argc != 4)
	{
		ft_putchar('\n');
		return (0);
	}
	printf("%i", ft_proga(argv));
	return (0);
}
