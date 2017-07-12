/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_lib.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 19:51:51 by sromanet          #+#    #+#             */
/*   Updated: 2017/05/07 19:52:11 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**str_new(char **str, char *line, int n)
{
	char	**tmp;
	int		i;

	tmp = (char **)malloc(sizeof(char *) * n);
	i = -1;
	if (n > 1)
	{
		while (++i < n - 1)
			tmp[i] = ft_strdup(str[i]);
		tmp[i] = ft_strdup(line);
	}
	else
		tmp[++i] = ft_strdup(line);
	i = -1;
	if (str)
		while (++i < n - 1)
			free(str[i]);
	if (str)
		free(str);
	if (line)
		free(line);
	return (tmp);
}

float	*floatnew(int n)
{
	int		i;
	float	*str;

	str = (float *)malloc(sizeof(float) * n);
	i = -1;
	while (++i < n)
		str[i] = 0;
	return (str);
}

int		ft_dif(float p1, float p2)
{
	if (p2 - p1 >= 0)
		return (1);
	else
		return (-1);
}

int		ft_abs(int a)
{
	if (a >= 0)
		return (a);
	else
		return (-a);
}

void	freestr(char **str, int n, int i, int z)
{
	if (z)
		n += 1;
	while (++i < n)
		free(str[i]);
}
