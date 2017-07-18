/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 18:15:44 by sromanet          #+#    #+#             */
/*   Updated: 2017/07/18 18:15:46 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		n_rooms(char **tmp, int i, int n)
{
	char *ptr;

	while (tmp[++i])
	{
		ptr = ft_strchr(tmp[i], ' ');
		if (tmp[i][0] != '#' && ptr != NULL)
			n++;
	}
	return (n);
}

void	room(t_lem *lem, char *tmp, int flag, int r)
{
	char	**str;

	str = ft_strsplit(tmp, ' ');
	if (ft_strsplit_len(str) == 3)
	{
		lem->rooms[r].name = ft_strdup(str[0]);
		lem->rooms[r].x = ft_atoi(str[1]);
		lem->rooms[r].y = ft_atoi(str[2]);
	}
	else if (flag == 0)
		lem->error = 1;
	ft_strsplit_free(str);
	if (flag == 1)
		lem->start = r;
	else if (flag == 2)
		lem->end = r;
}

void	create_rooms(t_lem *lem, int n, int i, int j)
{
	lem->rooms = (t_room *)malloc(sizeof(t_room) * (n));
	lem->connect = (int **)malloc(sizeof(int *) * (n + 1));
	while (++i < n)
	{
		lem->connect[i] = (int *)malloc(sizeof(int) * n);
		j = -1;
		while (++j < n)
		{
			lem->connect[i][j] = 0;
			if (j == i)
				lem->connect[i][j] = -1;
		}
	}
	lem->connect[i] = NULL;
}

void	filling2(t_lem *lem, char *ptr, char *tmp)
{
	char *ptr2;

	ptr2 = ft_strchr(tmp, '-');
	if (ptr2 != NULL)
		connect(lem, tmp, -1);
	if (ptr == NULL && ptr2 == NULL && ft_strlen(tmp) > 0
					&& !ft_isdigit(tmp[0]) && tmp[0] != '#')
		lem->error = 1;
}

void	filling(t_lem *lem, int i, int r)
{
	char	**tmp;
	char	*ptr;

	tmp = ft_strsplit(lem->input, '\n');
	lem->n_rooms = n_rooms(tmp, -1, 0);
	create_rooms(lem, lem->n_rooms, -1, -1);
	while (tmp[++i])
	{
		ptr = ft_strchr(tmp[i], ' ');
		if (ptr != NULL && tmp[i][0] != '#')
			room(lem, tmp[i], 0, r++);
		else if (ft_strequ(tmp[i], "##start\0"))
			room(lem, tmp[i], 1, r);
		else if (ft_strequ(tmp[i], "##end\0"))
			room(lem, tmp[i], 2, r);
		else
			filling2(lem, ptr, tmp[i]);
	}
	ft_strsplit_free(tmp);
	if (lem->start == -1 || lem->end == -1)
		lem->error = 1;
}
