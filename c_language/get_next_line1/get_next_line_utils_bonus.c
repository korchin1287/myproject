/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofloren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 00:50:32 by nofloren          #+#    #+#             */
/*   Updated: 2020/06/06 01:28:33 by nofloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		i;
	int		j;
	char	*dst;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	dst = (char*)malloc(sizeof(char) * (len + 1));
	j = 0;
	i = 0;
	if (!dst)
		return (NULL);
	while (s1[j] != '\0')
	{
		dst[i + j] = s1[j];
		j++;
	}
	while (s2[i] != '\0')
	{
		dst[i + j] = s2[i];
		i++;
	}
	dst[i + j] = '\0';
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	if (c == '\0' && s[i] == '\0')
		return ((char*)s + i);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*dest;
	size_t	len;

	len = ft_strlen(s);
	dest = (char*)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
