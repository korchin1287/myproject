#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_word(char s)
{
	if (s == ' ' || s == '\t')
		return (0);
	else
		return (1);
}

int	main(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc != 2)
	{
		ft_putchar('\n');
		return (0);
	}
	while (argv[1][i] != '\0')
	{
		if (ft_word(argv[1][i]) && argv[1][i])
		{
			while (ft_word(argv[1][i]) && argv[1][i])
			{
				ft_putchar(argv[1][i]);
				i++;
			}
			ft_putchar('\n');
			return (0);
		}
		i++;
	}
	ft_putchar ('\n');
	return (0);
}
