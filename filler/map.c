/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 00:02:54 by sromanet          #+#    #+#             */
/*   Updated: 2017/06/11 04:28:23 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_pos(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int		kpoint(t_fil *f, int ym, int xm, int k)
{
	int y;
	int x;

	y = -1;
	while (++y < f->size_my)
	{
		x = -1;
		while (++x < f->size_mx)
		{
			if (f->map[y][x] == f->ouc)
				k += f->k / (ft_pos(y - ym) + ft_pos(x - xm));
			else if (f->map[y][x] == f->olc)
				k += (f->k + 500) / (ft_pos(y - ym) + ft_pos(x - xm));
			else if (f->map[y][x] == f->uc || f->map[y][x] == f->lc)
				k += -f->k / (ft_pos(y - ym) + ft_pos(x - xm));
		}
	}
	return (k);
}

void	fill_koef(t_fil *f, int y, int x)
{
	if (!f->koef)
		f->koef = new_koef(f->size_my, f->size_mx, -1, -1);
	while (++y < f->size_my)
	{
		x = -1;
		while (++x < f->size_mx)
		{
			if (f->map[y][x] == '.')
				f->koef[y][x] = kpoint(f, y, x, 0);
			else if (f->map[y][x] == f->ouc)
				f->koef[y][x] = f->k * 15;
			else if (f->map[y][x] == f->olc)
				f->koef[y][x] = f->k * 20;
			else if (f->map[y][x] == f->uc || f->map[y][x] == f->lc)
				f->koef[y][x] = f->k * -10;
		}
	}
}

void	new_piece(t_fil *f, int py)
{
	char	*line;

	if (f->piece)
		ft_strsplit_free(f->piece);
	f->piece = (char **)malloc(sizeof(char *) * (f->size_py + 1));
	while (++py < f->size_py && get_next_line(f->fd, &line) == 1)
	{
		f->piece[py] = ft_strdup(line);
		ft_strdel(&line);
	}
	f->piece[py] = NULL;
}

void	fill_map(t_fil *f, int my, int k)
{
	char	*line;
	char	**tmp;

	if (f->start)
		miss_two_line(f);
	while (++my < f->size_my && get_next_line(f->fd, &line) == 1)
	{
		if (!k)
			k = ft_strlen(line) - f->size_mx;
		f->map[my] = ft_strcpy(f->map[my], line + k);
		ft_strdel(&line);
	}
	if (get_next_line(f->fd, &line) == 1)
	{
		tmp = ft_strsplit(line, ' ');
		if (tmp && ft_strequ(tmp[0], "Piece\0"))
		{
			f->size_py = ft_atoi(tmp[1]);
			f->size_px = ft_atoi(tmp[2]);
			ft_strsplit_free(tmp);
			new_piece(f, -1);
		}
	}
	f->start = 1;
	fill_koef(f, -1, -1);
}
