/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_lib_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 21:42:54 by sromanet          #+#    #+#             */
/*   Updated: 2017/05/09 21:42:59 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	freeall(t_img *fdf, int i)
{
	free(fdf->pix->x_def);
	free(fdf->pix->y_def);
	free(fdf->pix->z_def);
	free(fdf->pix->x);
	free(fdf->pix->y);
	free(fdf->pix->z);
	while (++i < fdf->pix->w * fdf->pix->h)
	{
		free(fdf->pix->color_d[i]);
		free(fdf->pix->color[i]);
	}
	free(fdf->pix->color_d);
	free(fdf->pix->color);
	free(fdf->pix);
	free(fdf->mlx);
	free(fdf);
}

void	destroy(t_img *fdf)
{
	mlx_destroy_image(fdf->mlx->mlx, fdf->mlx->img);
	mlx_clear_window(fdf->mlx->mlx, fdf->mlx->win);
	mlx_destroy_window(fdf->mlx->mlx, fdf->mlx->win);
	freeall(fdf, -1);
	exit(0);
}

void	redraw(t_img *fdf)
{
	mlx_destroy_image(fdf->mlx->mlx, fdf->mlx->img);
	fdf->mlx->img = mlx_new_image(fdf->mlx->mlx, fdf->mlx->w_px,
		fdf->mlx->h_px);
	fdf->mlx->str = mlx_get_data_addr(fdf->mlx->img, &fdf->mlx->bpp,
		&fdf->mlx->size_l, &fdf->mlx->e);
	draw_img(fdf, 0, -1, 0);
	mlx_put_image_to_window(fdf->mlx->mlx, fdf->mlx->win, fdf->mlx->img, 0, 0);
}

void	change_color(t_img *fdf, int i)
{
	while (++i < fdf->pix->w * fdf->pix->h)
	{
		if (fdf->pix->z_def[i] < 0)
		{
			fdf->pix->color[i][0] = 19;
			fdf->pix->color[i][1] = 69;
			fdf->pix->color[i][2] = 139;
		}
		else if (fdf->pix->z_def[i] == 0)
		{
			fdf->pix->color[i][0] = 0;
			fdf->pix->color[i][1] = 128;
			fdf->pix->color[i][2] = 0;
		}
		else
		{
			fdf->pix->color[i][0] = 128;
			fdf->pix->color[i][1] = 0;
			fdf->pix->color[i][2] = 0;
		}
	}
}
