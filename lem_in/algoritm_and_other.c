/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm_and_other.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 20:41:38 by sromanet          #+#    #+#             */
/*   Updated: 2017/07/13 20:41:40 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	connect(t_lem *lem, char *str, int i)
{
	char	**tmp;
	int		a;
	int		b;

	a = -1;
	b = -1;
	tmp = ft_strsplit(str, '-');
	if (ft_strsplit_len(tmp) == 2)
	{
		while (++i < lem->n_rooms)
		{
			if (ft_strequ(lem->rooms[i].name, tmp[0]))
				a = i;
			else if (ft_strequ(lem->rooms[i].name, tmp[1]))
				b = i;
		}
		if (a != -1 && b != -1)
		{
			lem->connect[a][b] = 1;
			lem->connect[b][a] = 1;
		}
	}
	ft_strsplit_free(tmp);
}

int		algoritm(t_lem *lem, int k, int n, int f)
{
	int		i;

	if ((n == lem->start && k != 0) || lem->way[f][k] == lem->end)
		return (1);
	i = -1;
	while (++i < lem->n_rooms)
	{
		if (lem->connect[n][i] == 1 && i != lem->start)
		{
			if (k == 0 || i != lem->way[f][k - 1])
			{
				lem->way[f][++k] = i;
				if (i != lem->end)
					filling_con(lem, i);
				if (i == lem->end)
				{
					lem->way = create_int(lem, 1, ++lem->n_way);
					algoritm(lem, 0, lem->start, lem->n_way - 1);
				}
				else if (algoritm(lem, k, i, f))
					return (1);
			}
		}
	}
	return (0);
}

void	next_step(t_lem *lem, int a, int n, int i)
{
	int		flag;

	flag = 0;
	while (++n < lem->n_way - 1)
	{
		i = 0;
		while (++i < lem->n_rooms)
		{
			if (lem->way[n][i] >= 0 && (lem->connect[0][lem->way[n][i]] == 0
			|| lem->way[n][i] == lem->end) && lem->ant[a] == lem->way[n][i - 1])
			{
				lem->connect[0][lem->way[n][i - 1]] -= 1;
				lem->connect[0][lem->way[n][i]] += 1;
				lem->ant[a] = lem->way[n][i];
				ft_printf("L%d-%s ", a + 1, lem->rooms[lem->way[n][i]].name);
				flag = 1;
				break ;
			}
		}
		if (flag)
			break ;
	}
}

void	filling_con(t_lem *lem, int i)
{
	int		q;

	q = -1;
	while (++q < lem->n_rooms)
		lem->connect[q][i] = 2;
}

void	free_connect_tab(t_lem *lem, int i, int n)
{
	while (++i < lem->n_rooms)
	{
		n = -1;
		while (++n < lem->n_rooms)
		{
			if (i == 0 && n == lem->start)
				lem->connect[i][n] = lem->ants;
			else
				lem->connect[i][n] = 0;
		}
	}
}
