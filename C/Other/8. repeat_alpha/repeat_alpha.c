#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_alfabet(char *str)
{
	int i;
	int j;
	
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 65 && str[i] <= 90)
		{
			j = 64;
			while ((str[i] - j) != 0)
			{
				ft_putchar(str[i]);
				j++;
			}
		}
		else if (str[i] >= 97 && str[i] <= 122)
		{
			j = 96;
			while ((str[i] - j) != 0)
			{
				ft_putchar(str[i]);
				j++;
			}
		}
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
	ft_alfabet(argv[1]);
	ft_putchar('\n');
	return (0);
}
