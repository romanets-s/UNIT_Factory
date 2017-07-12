/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 22:14:13 by sromanet          #+#    #+#             */
/*   Updated: 2017/01/11 17:07:22 by sprosian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		**ft_fill_cord(void)
{
	int **cord;
	int i;

	if ((cord = (int **)malloc(sizeof(int *) * 2)) == NULL)
		return (NULL);
	i = -1;
	while (++i < 2)
	{
		if ((cord[i] = (int *)malloc(sizeof(int) * 4)) == NULL)
			return (NULL);
	}
	return (cord);
}

int		ft_search_hash(char **buf, int **cord, int x, int i)
{
	int y;

	y = 0;
	while (y < 4)
	{
		if (buf[x][y] == '#' && i == 0)
		{
			cord[0][i] = x;
			cord[1][i] = y;
			i++;
			y++;
		}
		else if (buf[x][y] == '#' && i != 0)
		{
			cord[0][i] = x - cord[0][0];
			cord[1][i] = y - cord[1][0];
			i++;
			y++;
		}
		else
			y++;
	}
	return (i);
}

int		**ft_cord(char **buf, int **cord)
{
	int x;
	int i;

	x = -1;
	i = 0;
	while (++x < 4)
	{
		i = ft_search_hash(buf, cord, x, i);
	}
	cord[0][0] = 0;
	cord[1][0] = 0;
	return (cord);
}
