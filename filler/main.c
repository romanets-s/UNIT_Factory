/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 21:58:42 by sromanet          #+#    #+#             */
/*   Updated: 2017/06/11 00:08:51 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			search_p(t_fil *f, int my, int mx, int p)
{
	int y;
	int x;

	f->n = 0;
	if (my + f->size_py < f->size_my && mx + f->size_px < f->size_mx)
	{
		y = -1;
		while (++y < f->size_py)
		{
			x = -1;
			while (++x < f->size_px)
			{
				if (f->map[my + y][mx + x] == '.')
					f->n++;
				else if (f->map[my + y][mx + x] != '.' && f->piece[y][x] == '.')
					f->n++;
				if ((f->map[my + y][mx + x] == f->uc
				|| f->map[my + y][mx + x] == f->lc) && f->piece[y][x] == '*')
					p++;
			}
		}
		if (f->n + p == f->size_py * f->size_px && p == 1)
			return (1);
	}
	return (0);
}

long int	value(t_fil *f, int my, int mx, long int v)
{
	int y;
	int x;

	y = -1;
	while (++y < f->size_py)
	{
		x = -1;
		while (++x < f->size_px)
			v += f->koef[my + y][mx + x];
	}
	return (v);
}

void		search(t_fil *f, int y, int x, long int v)
{
	while (++y < f->size_my)
	{
		x = -1;
		while (++x < f->size_mx)
		{
			if (search_p(f, y, x, 0))
				v = value(f, y, x, 0);
			if (v > f->value)
			{
				f->value = v;
				f->pozy = y;
				f->pozx = x;
			}
		}
	}
}

int			main(void)
{
	t_fil	*f;

	f = (t_fil *)malloc(sizeof(t_fil));
	filler_init(f);
	if (f->error)
		return (EXIT_FAILURE);
	while (1)
	{
		if (!f->map)
			creat_map(f, -1);
		fill_map(f, -1, 0);
		if (f->error)
			return (EXIT_FAILURE);
		search(f, -1, -1, LONG_MIN);
		ft_printf("%d %d\n", f->pozy, f->pozx);
		f->pozy = -1;
		f->pozx = -1;
		f->value = LONG_MIN;
	}
	return (EXIT_SUCCESS);
}
