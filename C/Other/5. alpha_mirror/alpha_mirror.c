#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_mirror(char *str)
{
	int i;
	int j;

	i = 0;
	while (str[i] !='\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			ft_putchar('Z' - str[i] + 'A');
		else if (str[i] >= 'a' && str[i] <= 'z')
			ft_putchar('z' - str[i] + 'a');
		else
			ft_putchar(str[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putchar('\n');
		return (0);
	}
	ft_mirror(argv[1]);
	ft_putchar ('\n');
	return (0);
}
