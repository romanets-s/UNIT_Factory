/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 20:41:30 by sromanet          #+#    #+#             */
/*   Updated: 2017/07/13 20:41:32 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_strsplit_len(char **split)
{
	int		i;

	i = 0;
	if (split == NULL)
		return (0);
	else
		while (split[i] != NULL)
			i++;
	return (i);
}

void	ft_strsplit_free(char **split)
{
	int i;

	i = 0;
	if (split)
	{
		if ((i = ft_strsplit_len(split)) > 0)
		{
			while (i >= 0)
			{
				ft_strdel(&split[i]);
				i--;
			}
			free(split);
			split = NULL;
		}
	}
}
