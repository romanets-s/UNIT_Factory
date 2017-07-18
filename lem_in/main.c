/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 20:41:15 by sromanet          #+#    #+#             */
/*   Updated: 2017/07/13 20:41:21 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	start_finish(t_lem *lem, int a)
{
	while (++a < lem->ants)
		ft_printf("L%d-%s ", a + 1, lem->rooms[lem->end].name);
	ft_printf("\n");
}

void	finish(t_lem *lem, int a)
{
	ft_printf("%s\n\n", lem->input + 1);
	while (lem->connect[0][lem->end] != lem->ants)
	{
		a = -1;
		while (++a < lem->ants)
			if (lem->ant[a] != lem->end)
				next_step(lem, a, -1, 0);
		ft_printf("\n");
	}
}

void	check_error(t_lem *lem, int n, int i)
{
	int ok;

	ok = 0;
	while (++n < lem->n_way - 1 && ok == 0)
	{
		i = -1;
		while (++i != lem->n_rooms && ok == 0)
		{
			if (lem->way[n][i] == lem->end)
				ok = 1;
		}
	}
	if (!ok)
		lem->error = 1;
}

int		error(t_lem *lem)
{
	if (lem->error == 1)
	{
		ft_printf("ERROR\n");
		return (1);
	}
	else
		return (0);
}

int		main(void)
{
	t_lem	*lem;

	lem = create_s();
	input(lem);
	if (error(lem) == 1)
		return (EXIT_FAILURE);
	filling(lem, 0, 0);
	if (lem->error != 1 && lem->connect[lem->start][lem->end] == 1)
	{
		start_finish(lem, -1);
		return (EXIT_SUCCESS);
	}
	if (error(lem) == 1)
		return (EXIT_FAILURE);
	lem->way = create_int(lem, 0, ++lem->n_way);
	algoritm(lem, 0, lem->start, lem->n_way - 1);
	check_error(lem, -1, -1);
	create_ant(lem, -1);
	free_connect_tab(lem, -1, -1);
	if (error(lem) == 1)
		return (EXIT_FAILURE);
	else
		finish(lem, 0);
	return (EXIT_SUCCESS);
}
