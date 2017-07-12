/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 20:47:16 by sromanet          #+#    #+#             */
/*   Updated: 2017/05/07 20:47:21 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	line_x(t_img *fdf, int p1, int p2, int l)
{
	int n;

	while (l--)
	{
		fdf->tmp = fdf->x * 4 + fdf->mlx->w_px * 2;
		n = fdf->tmp + (fdf->y * fdf->mlx->size_l + fdf->mlx->h_px / 2
			* fdf->mlx->size_l);
		if (n >= 0 && n < fdf->mlx->w_px * fdf->mlx->h_px * 4 && !(n % 4)
			&& fdf->tmp >= 0 && fdf->tmp < fdf->mlx->size_l)
		{
			fdf->mlx->str[n] = (char)(fdf->pix->color[p1][0] * l / fdf->len
				+ fdf->pix->color[p2][0] * (1 - l / fdf->len));
			fdf->mlx->str[n + 1] = (char)(fdf->pix->color[p1][1] * l / fdf->len
				+ fdf->pix->color[p2][1] * (1 - l / fdf->len));
			fdf->mlx->str[n + 2] = (char)(fdf->pix->color[p1][2] * l / fdf->len
				+ fdf->pix->color[p2][2] * (1 - l / fdf->len));
		}
		fdf->x += ft_dif(fdf->pix->x[p1], fdf->pix->x[p2]);
		fdf->d += 2 * fdf->lengthy;
		if (fdf->d > 0)
		{
			fdf->d -= 2 * fdf->lengthx;
			fdf->y += ft_dif(fdf->pix->y[p1], fdf->pix->y[p2]);
		}
	}
}

void	line_y(t_img *fdf, int p1, int p2, int l)
{
	int n;

	while (l--)
	{
		fdf->tmp = fdf->x * 4 + fdf->mlx->w_px * 2;
		n = fdf->tmp + (fdf->y * fdf->mlx->size_l + fdf->mlx->h_px / 2
			* fdf->mlx->size_l);
		if (n >= 0 && n < fdf->mlx->w_px * fdf->mlx->h_px * 4 && !(n % 4)
			&& fdf->tmp >= 0 && fdf->tmp < fdf->mlx->size_l)
		{
			fdf->mlx->str[n] = (char)(fdf->pix->color[p1][0] * l / fdf->len
				+ fdf->pix->color[p2][0] * (1 - l / fdf->len));
			fdf->mlx->str[n + 1] = (char)(fdf->pix->color[p1][1] * l / fdf->len
				+ fdf->pix->color[p2][1] * (1 - l / fdf->len));
			fdf->mlx->str[n + 2] = (char)(fdf->pix->color[p1][2] * l / fdf->len
				+ fdf->pix->color[p2][2] * (1 - l / fdf->len));
		}
		fdf->y += ft_dif(fdf->pix->y[p1], fdf->pix->y[p2]);
		fdf->d += 2 * fdf->lengthx;
		if (fdf->d > 0)
		{
			fdf->d -= 2 * fdf->lengthy;
			fdf->x += ft_dif(fdf->pix->x[p1], fdf->pix->x[p2]);
		}
	}
}

void	line(t_img *fdf, int p1, int p2)
{
	int l;

	fdf->lengthx = ft_abs((int)(fdf->pix->x[p2] - fdf->pix->x[p1]));
	fdf->lengthy = ft_abs((int)(fdf->pix->y[p2] - fdf->pix->y[p1]));
	if (fdf->lengthx > fdf->lengthy)
		l = fdf->lengthx + 1;
	else
		l = fdf->lengthy + 1;
	fdf->len = (double)l;
	fdf->x = fdf->pix->x[p1];
	fdf->y = fdf->pix->y[p1];
	if (fdf->lengthy <= fdf->lengthx)
	{
		fdf->d = -fdf->lengthx;
		line_x(fdf, p1, p2, l);
	}
	else
	{
		fdf->d = -fdf->lengthy;
		line_y(fdf, p1, p2, l);
	}
}

void	draw_img_help(t_img *fdf, int n, int i)
{
	fdf->mlx->str[n] = fdf->pix->color[i][0];
	fdf->mlx->str[n + 1] = fdf->pix->color[i][1];
	fdf->mlx->str[n + 2] = fdf->pix->color[i][2];
	fdf->mlx->str[n + 3] = fdf->pix->color[i][3];
}

void	draw_img(t_img *fdf, int n, int yi, int xx)
{
	int xi;
	int tmp;

	while (++yi < fdf->pix->h)
	{
		xi = -1;
		while (++xi < fdf->pix->w)
		{
			if (xi < fdf->pix->w - 1)
				line(fdf, xx + xi, xx + xi + 1);
			if (yi < fdf->pix->h - 1)
				line(fdf, xx + xi, xx + xi + fdf->pix->w);
			tmp = (int)(ceil(fdf->pix->x[xx + xi]) * 4 + fdf->mlx->w_px * 2);
			n = tmp + (int)(ceil(fdf->pix->y[xx + xi]) * fdf->mlx->size_l
									+ fdf->mlx->h_px / 2 * fdf->mlx->size_l);
			if (n >= 0 && n < fdf->mlx->w_px * fdf->mlx->h_px * 4 && !(n % 4)
									&& tmp >= 0 && tmp < fdf->mlx->size_l)
				draw_img_help(fdf, n, xx + xi);
		}
		xx += fdf->pix->w;
	}
}
