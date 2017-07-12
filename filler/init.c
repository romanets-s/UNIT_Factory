/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 00:08:38 by sromanet          #+#    #+#             */
/*   Updated: 2017/06/11 00:40:53 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	miss_two_line(t_fil *f)
{
	char	*line;
	char	**tmp;

	if (get_next_line(f->fd, &line) == 1)
	{
		tmp = ft_strsplit(line, ' ');
		ft_strdel(&line);
		if (!ft_strequ(tmp[0], "Plateau\0") && !(ft_atoi(tmp[1]) == f->size_my
										&& ft_atoi(tmp[2]) == f->size_mx))
			f->error = 1;
		ft_strsplit_free(tmp);
	}
	if (get_next_line(f->fd, &line) == 1)
		ft_strdel(&line);
}

int		**new_koef(int y, int x, int n, int i)
{
	int	**new;

	new = (int **)malloc(sizeof(int *) * (y + 1));
	while (++n < y)
	{
		new[n] = (int *)malloc(sizeof(int) * x);
		i = -1;
		while (++i < x)
			new[n][i] = 0;
	}
	new[n] = NULL;
	return (new);
}

void	creat_map(t_fil *f, int n)
{
	char	*line;
	char	**str;

	if (get_next_line(f->fd, &line) == 1)
	{
		str = ft_strsplit(line, ' ');
		ft_strdel(&line);
		if (ft_strequ(str[0], "Plateau\0"))
		{
			f->size_my = ft_atoi(str[1]);
			f->size_mx = ft_atoi(str[2]);
		}
		ft_strsplit_free(str);
		f->map = (char **)malloc((sizeof(char *) * (f->size_my + 1)));
		while (++n < f->size_my)
			f->map[n] = ft_strnew(f->size_mx);
		f->map[n] = NULL;
		if (get_next_line(f->fd, &line) == 1)
			ft_strdel(&line);
	}
}

void	filler_vm(t_fil *f)
{
	char	*line;
	char	**str;

	if (get_next_line(f->fd, &line) == 1)
	{
		str = ft_strsplit(line, ' ');
		if (str && ft_strsplit_len(str) == 5 && ft_strequ(str[0], "$$$\0"))
		{
			f->player = str[2][1] - '0';
			if (f->player == 1)
				f->uc = 'O';
			else
				f->uc = 'X';
			f->lc = f->uc + 32;
			ft_strsplit_free(str);
		}
		ft_strdel(&line);
	}
	if (f->uc == 'O')
		f->ouc = 'X';
	else
		f->ouc = 'O';
	f->olc = f->ouc + 32;
	if (f->player != 1 && f->player != 2)
		f->error = 1;
}

void	filler_init(t_fil *f)
{
	f->fd = 0;
	f->start = 0;
	f->error = 0;
	f->player = 0;
	f->uc = 0;
	f->lc = 0;
	f->ouc = 0;
	f->olc = 0;
	f->size_mx = -1;
	f->size_my = -1;
	f->size_px = -1;
	f->size_py = -1;
	f->piece = NULL;
	f->value = LONG_MIN;
	f->pozx = -1;
	f->pozy = -1;
	f->map = NULL;
	f->koef = NULL;
	f->k = 1000;
	f->n = 0;
	filler_vm(f);
}
