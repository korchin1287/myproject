#include "ft.h"

int	prov(char str)
{
	if (str == '\t' || str == '\n' || str == '\v')
		return (1);
	else if (str == '\f' || str == '\r' || str == ' ')
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	int i;
	int x;
	int rez;
	int k;

	rez = 0;
	x = 1;
	i = 0;
	k = 0;
	while (prov(str[i]) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			x = x * (-1);
		else
			x = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		rez = rez * 10 + (str[i] - 48) * x;
		i++;
	}
	return (rez);
}
