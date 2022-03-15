/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamcha <tyamcha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:39:28 by unix              #+#    #+#             */
/*   Updated: 2021/12/11 10:24:11 by tyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strch(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == c % 256)
			return ((char *)s);
		s++;
	}
	if (*s == c % 256)
		return ((char *)s);
	return (NULL);
}

size_t	ft_strl(const char *s)
{
	int	res;

	res = 0;
	if (!s)
		return (0);
	while (*s++)
		res++;
	return (res);
}

void	*ft_memm(void *dest, const void *src, size_t n)
{
	int	i;

	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest > src)
	{
		i = (int)n - 1;
		while (i >= 0)
		{
			*(char *)(dest + i) = *(char *)(src + i);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < (int)n)
		{
			*(char *)(dest + i) = *(char *)(src + i);
			i++;
		}
	}
	return (dest);
}

char	*ft_strjo(char const *s1, char const *s2)
{
	char	*res;
	size_t	res_len;

	if (!s1 && !s2)
		return (NULL);
	res_len = ft_strl(s1) + ft_strl(s2) + 1;
	res = (char *)malloc(res_len);
	if (!res)
		return (NULL);
	ft_memm(res, s1, ft_strl(s1));
	ft_memm(res + ft_strl(s1), s2, ft_strl(s2));
	res[res_len - 1] = '\0';
	return (res);
}
