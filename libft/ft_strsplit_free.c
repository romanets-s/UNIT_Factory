/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 19:54:03 by sromanet          #+#    #+#             */
/*   Updated: 2017/07/12 19:54:09 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
