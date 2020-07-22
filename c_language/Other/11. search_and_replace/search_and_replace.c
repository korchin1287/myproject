#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	search_and_replace(char **argv)
{
	int i;
	
	i = 0;
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] == argv[2][0])
			ft_putchar(argv[3][0]);
		else
			ft_putchar(argv[1][i]);
		i++;
	}
	ft_putchar('\n');
}

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (0);
}

int	main(int argc, char **argv)
{
	int len1;
	int len2;

	if (argc != 4)
	{
		ft_putchar('\n');
		return (0);
	}
	if ((!argv[2][1]) && (!argv[3][1]))
		search_and_replace(argv);
	else
		ft_putchar('\n');
	return (0);
}
