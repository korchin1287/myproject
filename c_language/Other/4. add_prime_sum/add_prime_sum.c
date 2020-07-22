#include <unistd.h>
#include <stdio.h>

int	ft_atoi(char *str)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while (str[i] != '\0')
	{
		x = x * 10 + (str[i] - '0');
		i++;
	}
	return (x);
}

int	ifPrime(int n)
{
	int i;

	i = 2;
	if (n > 1)
	{
		while (i < n)
		{
			if (n % i == 0)
				return (0);
			i++;
		}
		return (1);
	}
	else
		return (0);

}

int	ft_add_prime_sum(int x)
{
	int i;
	int sum;

	i = 0;
	sum = 0;
	while (i <= x)
	{
		if (ifPrime(i))
			sum = sum + i;
		i++;	
	}
	return (sum);
}

char	ft_putnbr(int nb)
{
	char c;

	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
	}
	if (nb < 10)
	{
		c = nb + '0';
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}	
}

int	main(int argc, char **argv)
{
	if (argc != 2 || (argv[1][0] == '-'))
	{
		write(1, "0\n", 2);
		return (0);
	}
	ft_putnbr(ft_add_prime_sum(ft_atoi(argv[1])));
	write(1, "\n", 1);
	return (0);
}
