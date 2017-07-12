/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 19:54:18 by sromanet          #+#    #+#             */
/*   Updated: 2017/07/12 19:54:21 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
