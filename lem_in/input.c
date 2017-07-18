/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 18:13:58 by sromanet          #+#    #+#             */
/*   Updated: 2017/07/18 18:15:39 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	input2(t_lem *lem, char *line)
{
	while (get_next_line(0, &line) > 0)
	{
		if (!ft_strlen(line) || line[0] == 'L')
			lem->error = 1;
		lem->input = strjoin_and_free(lem->input, line);
		ft_strdel(&line);
		if (lem->error == 1)
			break ;
	}
}

void	input(t_lem *lem)
{
	char	*line;

	line = NULL;
	lem->input = ft_strnew(-1);
	while (lem->ants == -1)
	{
		if (get_next_line(0, &line) > 0 && ft_strlen(line) > 0)
		{
			if (line[0] != '#' && ft_isdigit(line[0]))
				lem->ants = ft_atoi(line);
			if (ft_isalpha(line[0]) && line[0] != '#')
				lem->error = 1;
			lem->input = strjoin_and_free(lem->input, line);
			ft_strdel(&line);
		}
		if (lem->error)
			break ;
	}
	if (lem->error)
		return ;
	line = NULL;
	input2(lem, line);
}
