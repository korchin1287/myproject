#include <unistd.h>

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
		i++;
	return (i);
}

void	ft_hidenp(char *s1, char *s2)
{
	int i;
	int j;
	int count;
	int len;

	i = 0;
	j = 0;
	count = 0;
	while(s1[i] != '\0')
	{
		if (s1[i] != s2[j])
		{
			while (s1[i] != s2[j] && s2[j] != '\0')
			{
				j++;
				if (s1[i] == s2[j])
					count++;
			}
			 if (s2[j] == '\0')
                          break ;
			i++;
			j++;
		}		
		if (s1[i] == s2[j])
		{
			count++;
			i++;
			j++;
		}
	}
	if (count == ft_strlen(s1))
		write(1, "1", 1);
	else
		write(1, "0", 1);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	if (argv[0][1] == '\0')
	{
		write(1, "1\n", 2);
		return(0);
	}
	ft_hidenp(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
