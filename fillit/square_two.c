/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprosian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 17:56:42 by sprosian          #+#    #+#             */
/*   Updated: 2017/01/28 19:40:31 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_del_square(char **square, int c)
{
	int i;

	i = -1;
	while (++i <= c)
		free(square[i]);
	free(square);
}

int			ft_size_square(t_figure *list)
{
	int		i;
	int		c;

	i = 0;
	c = 2;
	while (list != NULL)
	{
		list = list->next;
		i++;
	}
	i = i * 4;
	while ((c * c) < i)
		c++;
	return (c);
}

char		**ft_create_square(int c)
{
	int		i;
	int		n;
	char	**square;

	if ((square = (char **)malloc(sizeof(char *) * c + 1)) == NULL)
		return (NULL);
	i = -1;
	while (++i < c)
	{
		if ((square[i] = (char *)malloc(sizeof(char) * c + 1)) == NULL)
			return (NULL);
		n = 0;
		while (n < c)
			square[i][n++] = '.';
		square[i][n] = '\0';
	}
	square[i] = 0;
	return (square);
}

int			ft_check_square(t_figure *list, char **square, int tab[2], int c)
{
	int		i;
	int		flag;
	int		**cord;
	int		x;
	int		y;

	x = tab[0];
	y = tab[1];
	cord = list->cord;
	i = -1;
	flag = 0;
	while (++i < 4)
	{
		if (x + cord[0][i] >= 0 && y + cord[1][i] >= 0 && x + cord[0][i] < c
			&& y + cord[1][i] < c
			&& square[x + cord[0][i]][y + cord[1][i]] == '.')
			flag++;
	}
	if (flag == 4)
		return (1);
	return (0);
}
