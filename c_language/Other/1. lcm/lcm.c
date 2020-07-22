#include <stdio.h>

unsigned int	hcf(unsigned int a, unsigned int b)
{
	int i;

	if (a == b)
		return (a);
	else if (a < b)
	{
		i = a;
		a = b;
		b = i;
	}
	else
		a = a - b;
	hcf(a, b);
}

unsigned int	lcm(unsigned int a, unsigned int b)
{
	int i;

	i = (a * b) / hcf(a, b);
	return (i);

}

int		main(void)
{
	printf("%i\n", lcm(30, 12));
	return(0);
}
