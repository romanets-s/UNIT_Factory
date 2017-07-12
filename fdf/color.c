/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 19:59:48 by sromanet          #+#    #+#             */
/*   Updated: 2017/05/07 20:00:04 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	color_copy(t_pix *pix, int n, int i)
{
	while (++i < 4)
		pix->color[n][i] = pix->color_d[n][i];
	if (pix->color[n][0] == 0 && pix->color[n][1] == 0 && pix->color[n][2] == 0)
	{
		pix->color[n][0] = 255;
		pix->color[n][1] = 255;
		pix->color[n][2] = 255;
	}
}

void	color(t_pix *pix, char *c, int n, int i)
{
	int	a;
	int	m;

	while (c[++i] != '\0')
	{
		if (c[i] == ',' && c[i + 1] == '0')
		{
			i += 2;
			a = 0;
			m = 2;
			while (c[++i] != '\0')
			{
				if (!(a % 2) && a != 0)
					m--;
				if (c[i] >= '0' && c[i] <= '9')
					pix->color_d[n][m] = pix->color_d[n][m] * 16 + (c[i] - 48);
				else if (c[i] >= 'a' && c[i] <= 'f')
					pix->color_d[n][m] = pix->color_d[n][m] * 16 + (c[i] - 87);
				else if (c[i] >= 'A' && c[i] <= 'F')
					pix->color_d[n][m] = pix->color_d[n][m] * 16 + (c[i] - 55);
				a++;
			}
		}
	}
	color_copy(pix, n, -1);
}
