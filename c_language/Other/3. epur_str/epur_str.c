#include <unistd.h>

int	ft_space(char *str, int i)
{
	while(str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '\t')
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_word(char c)
{
	if (!(c == ' ' || c == '\t'))
		return (1);
	else
		return (0);
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
		i++;
	return (i);
}

void	ft_epur_str(char *str)
{
	int i;

	i = 0;
	while (i <= ft_strlen(str))
	{
		if (ft_word(str[i]))
		{
			while (ft_word(str[i]) && str[i] != '\0')
			{
				write(1, &str[i], 1);
				i++;
			}
			if (!(ft_space(str, i)))
				write(1, " ", 1);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	ft_epur_str(argv[1]);
	write(1, "\n", 1);
	return (0);
}
