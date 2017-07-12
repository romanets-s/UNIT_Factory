/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprosian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:43:01 by sprosian          #+#    #+#             */
/*   Updated: 2017/01/11 20:05:25 by sprosian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_buf(char *buf)
{
	char	**tmp;
	int		i;
	int		j;
	int		x;

	if ((tmp = (char **)malloc(sizeof(char *) * 5)) == NULL)
		return (NULL);
	i = -1;
	x = 0;
	while (++i < 4)
	{
		if ((tmp[i] = (char *)malloc(sizeof(char) * 5)) == NULL)
			return (NULL);
		j = -1;
		while (++j < 5)
		{
			if (*buf == '\n')
				tmp[i][j] = '\0';
			else
				tmp[i][j] = buf[x];
			x++;
		}
	}
	tmp[i] = NULL;
	return (tmp);
}

char	*ft_fill_buf(char *buf)
{
	char	*fill;
	int		i;

	if ((fill = (char *)malloc(sizeof(char) * 22)) == NULL)
		return (NULL);
	i = -1;
	ft_bzero(fill, 22);
	while (++i < 22)
		fill[i] = buf[i];
	return (fill);
}
