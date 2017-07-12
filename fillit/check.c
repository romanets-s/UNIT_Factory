/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprosian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 18:03:02 by sprosian          #+#    #+#             */
/*   Updated: 2017/01/25 23:04:11 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_hash_size(char *buf)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 20)
	{
		if (buf[i] == '#')
			j++;
		i++;
	}
	if (j == 4)
		return (0);
	return (1);
}

int		ft_check_newline(char *buf, int i, int j)
{
	if (ft_strlen(buf) == 20)
	{
		while (i < 20)
		{
			if (buf[i] == '\n')
				j++;
			i++;
		}
		if (j == 4)
			return (0);
	}
	if (ft_strlen(buf) == 21)
	{
		while (i < 21)
		{
			if (buf[i] == '\n')
				j++;
			i++;
		}
		if (j == 5)
			return (0);
	}
	return (1);
}

int		ft_check_figure(char *buf)
{
	int i;
	int flag;

	i = 0;
	while (i < 20)
	{
		flag = 0;
		if (buf[i] == '#')
		{
			if ((i - 5) >= 0 && buf[i - 5] == '#')
				flag++;
			if ((i + 5) <= 18 && buf[i + 5] == '#')
				flag++;
			if ((i - 1) >= 0 && buf[i - 1] == '#')
				flag++;
			if ((i + 1) <= 18 && buf[i + 1] == '#')
				flag++;
			if (flag != 1 && flag != 2 && flag != 3)
				return (1);
		}
		i++;
	}
	if (ft_check_figure_two(buf, -1, 0) == 0)
		return (0);
	return (1);
}

int		ft_check_figure_two(char *buf, int i, int j)
{
	int flag;

	while (++i < 20)
	{
		flag = 0;
		if (buf[i] == '#')
		{
			if ((i - 5) >= 0 && buf[i - 5] == '#')
				flag++;
			if ((i + 5) <= 18 && buf[i + 5] == '#')
				flag++;
			if ((i - 1) >= 0 && buf[i - 1] == '#')
				flag++;
			if ((i + 1) <= 18 && buf[i + 1] == '#')
				flag++;
			if (flag == 3)
				return (0);
			if (flag == 2)
				j++;
		}
	}
	if (j == 2 || j == 4)
		return (0);
	return (1);
}

int		ft_check_point(char *buf)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (buf[i])
	{
		if (buf[i] == '.')
			n++;
		i++;
	}
	if (n == 12)
		return (0);
	return (1);
}
