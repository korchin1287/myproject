#include <unistd.h>

void	ft_putchar(char c)
{
    write(1, &c, 1);
}

void	func(int nb)
{
	int i;

	i = nb % 10;
	nb = nb / 10;
	if (nb != 0)
	{
		func(nb);
	}
	if (i < 0)
	{
		ft_putchar(i * (-1) + 48);
	}
	else
	{
		ft_putchar(i + 48);
	}
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
	}
	func(nb);
}
