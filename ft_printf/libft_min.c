/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_min.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 21:55:50 by sromanet          #+#    #+#             */
/*   Updated: 2017/03/23 22:23:05 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_first_zero(char *s, int a, int b)
{
	char *new;

	if (!s)
		new = ft_strnew(1);
	else
		new = ft_strnew(ft_strlen(s) + 1);
	new[0] = '0';
	if (s)
		while (s[a])
			new[b++] = s[a++];
	free(s);
	return (new);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s)
		while (s[i])
			i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	char *p;

	p = (char *)s;
	if (n > 0)
		while (n--)
			*p++ = '\0';
}

char	*ft_strnew(size_t size)
{
	char	*s;

	s = (char *)malloc(sizeof(char) * (size + 1));
	if (s)
		ft_bzero(s, size + 1);
	return (s);
}
