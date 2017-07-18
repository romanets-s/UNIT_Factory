/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_and_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 20:41:54 by sromanet          #+#    #+#             */
/*   Updated: 2017/07/13 20:41:56 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_lem	*create_s(void)
{
	t_lem	*lem;

	lem = (t_lem *)malloc(sizeof(t_lem));
	lem->input = NULL;
	lem->ants = -1;
	lem->connect = NULL;
	lem->n_rooms = -1;
	lem->rooms = NULL;
	lem->start = -1;
	lem->end = -1;
	lem->way = NULL;
	lem->n_way = 0;
	lem->error = 0;
	return (lem);
}

char	*strjoin_and_free(char *s1, char *s2)
{
	char *fresh;
	char *ptr;
	char *tmp;

	tmp = NULL;
	fresh = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if (fresh)
	{
		tmp = fresh;
		ptr = s1;
		while (*s1)
			*(fresh++) = *(s1++);
		*(fresh++) = '\n';
		ft_strdel(&ptr);
		s1 = NULL;
		while (*s2)
			*(fresh++) = *(s2++);
		*fresh = '\0';
		s2 = NULL;
	}
	return (tmp);
}

void	ft_delint(int **tmp, int n)
{
	int i;

	i = -1;
	if (tmp && *tmp)
	{
		while (++i < n)
			free(tmp[i]);
		free(tmp);
		tmp = NULL;
	}
}

int		**create_int(t_lem *lem, int del, int n)
{
	int	**tmp;
	int	**ptr;
	int	i;
	int	t;

	ptr = NULL;
	if (del == 1)
		ptr = lem->way;
	tmp = (int **)malloc(sizeof(int *) * n);
	i = -1;
	while (++i < n)
	{
		tmp[i] = (int *)malloc(sizeof(int) * lem->n_rooms);
		t = -1;
		while (++t < lem->n_rooms)
		{
			if (del == 1 && i < n - 1)
				tmp[i][t] = ptr[i][t];
			else
				tmp[i][t] = -1;
			(t == 0) ? (tmp[i][t] = lem->start) : 0;
		}
	}
	ft_delint(ptr, n - 1);
	return (tmp);
}

void	create_ant(t_lem *lem, int i)
{
	lem->ant = (int *)malloc(sizeof(int) * lem->ants);
	while (++i < lem->ants)
		lem->ant[i] = lem->start;
}
