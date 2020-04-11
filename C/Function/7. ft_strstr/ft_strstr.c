char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int x;

	i = 0;
	x = 0;
	if (to_find[i] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		if (str[i] == to_find[x])
		{
			x = 0;
			while (to_find[x] != '\0' && to_find[x] == str[i + x])
			{
				if (str[i + x] == '\0')
					break ;
				x++;
			}
			if (to_find[x] == '\0')
				return (str + i);
		}
		i++;
	}
	return (0);
}
