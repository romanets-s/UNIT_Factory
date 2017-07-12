/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprosian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 17:01:15 by sprosian          #+#    #+#             */
/*   Updated: 2017/01/28 19:40:10 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_write_square(t_figure *list, char **square, int a, int b)
{
	int		i;
	int		**cord;

	cord = list->cord;
	i = -1;
	while (++i < 4)
		square[a + cord[0][i]][b + cord[1][i]] = list->alpha;
	return ;
}

void		ft_del_figure(char alpha, char **square)
{
	int		i;
	int		n;

	n = 0;
	while (square[n])
	{
		i = 0;
		while (square[n][i])
		{
			if (square[n][i] == alpha)
				square[n][i] = '.';
			i++;
		}
		n++;
	}
	return ;
}

int			ft_res_square_new(t_figure *list, int c, char **square)
{
	int		y;
	int		x;
	int		tab[2];

	if (list == NULL)
		return (1);
	x = -1;
	while (++x < c)
	{
		y = -1;
		while (++y < c)
		{
			tab[0] = x;
			tab[1] = y;
			if (ft_check_square(list, square, tab, c))
			{
				ft_write_square(list, square, x, y);
				if (ft_res_square_new(list->next, c, square))
					return (1);
				ft_del_figure(list->alpha, square);
			}
		}
	}
	return (0);
}

void		ft_print_result(char **square)
{
	int i;

	i = 0;
	while (square[i] != 0)
	{
		ft_putstr(square[i++]);
		write(1, "\n", 1);
	}
}

void		ft_res_square(t_figure *list)
{
	char	**square;
	int		c;
	int		n;

	c = ft_size_square(list);
	n = 0;
	while (n != 1)
	{
		square = ft_create_square(c);
		n = ft_res_square_new(list, c, square);
		if (n == 0)
		{
			ft_del_square(square, c);
			c++;
		}
	}
	ft_print_result(square);
	return ;
}
