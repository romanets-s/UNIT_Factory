/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_poz.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 19:51:28 by sromanet          #+#    #+#             */
/*   Updated: 2017/05/07 19:51:41 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rot_z(t_pix *pix, float r)
{
	int i;

	r = 0.01745329252 * r;
	i = -1;
	while (++i < pix->w * pix->h)
	{
		pix->x[i] = pix->x[i] * cos(r) + pix->y[i] * sin(r);
		pix->y[i] = pix->y[i] * cos(r) - pix->x[i] * sin(r);
	}
}

void	rot_y(t_pix *pix, float r)
{
	int i;

	r = 0.01745329252 * r;
	i = -1;
	while (++i < pix->w * pix->h)
	{
		pix->x[i] = pix->x[i] * cos(r) - pix->z[i] * sin(r);
		pix->z[i] = pix->z[i] * cos(r) + pix->x[i] * sin(r);
	}
}

void	rot_x(t_pix *pix, float r)
{
	int i;

	r = 0.01745329252 * r;
	i = -1;
	while (++i < pix->w * pix->h)
	{
		pix->y[i] = pix->y[i] * cos(r) + pix->z[i] * sin(r);
		pix->z[i] = pix->z[i] * cos(r) - pix->y[i] * sin(r);
	}
}

void	zoom(t_pix *pix, float zoom)
{
	int i;

	i = -1;
	while (++i < pix->w * pix->h)
	{
		pix->x[i] *= zoom;
		pix->y[i] *= zoom;
		pix->z[i] *= zoom;
	}
}
