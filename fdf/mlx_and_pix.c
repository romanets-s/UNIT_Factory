/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_and_pix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 19:52:18 by sromanet          #+#    #+#             */
/*   Updated: 2017/05/07 19:52:32 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_img	*create_img(char **str, int y, int x, char *name)
{
	t_img	*fdf;

	fdf = (t_img *)malloc(sizeof(t_img));
	fdf->width = x;
	fdf->height = y;
	if (x > y)
		fdf->k = 1000 / x;
	else
		fdf->k = 1000 / y;
	fdf->pix = create_pix(str, y, x, fdf->k);
	fdf->mlx = create_mlx(y, x, fdf->k, name);
	return (fdf);
}

t_mlx	*create_mlx(int y, int x, int k, char *name)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	mlx->mlx = mlx_init();
	mlx->w_px = x * k;
	if (mlx->w_px % 2)
		mlx->w_px += 1;
	mlx->h_px = y * k;
	mlx->win = mlx_new_window(mlx->mlx, mlx->w_px, mlx->h_px, name);
	mlx->img = mlx_new_image(mlx->mlx, mlx->w_px, mlx->h_px);
	mlx->str = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->size_l, &mlx->e);
	return (mlx);
}

void	create_pix_put(t_pix *pix, char **str, int k, int xx)
{
	int		yi;
	int		xi;
	int		n;
	char	**tmp;

	yi = -1;
	while (++yi < pix->h)
	{
		tmp = ft_strsplit(str[yi], ' ');
		xi = -1;
		while (++xi < pix->w)
		{
			n = xx + xi;
			pix->x_def[n] = (xi - pix->w / 2) * k;
			pix->y_def[n] = (yi - pix->h / 2) * k;
			pix->z_def[n] = ft_atoi(tmp[xi]) * k;
			pix->x[n] = pix->x_def[n];
			pix->y[n] = pix->y_def[n];
			pix->z[n] = pix->z_def[n];
			color(pix, tmp[xi], n, -1);
		}
		freestr(tmp, xi, -1, 1);
		xx += pix->w;
	}
	freestr(str, yi, -1, 0);
}

void	create_pix_init(t_pix *pix, int size)
{
	int i;
	int n;

	pix->x_def = floatnew(size);
	pix->y_def = floatnew(size);
	pix->z_def = floatnew(size);
	pix->x = floatnew(size);
	pix->y = floatnew(size);
	pix->z = floatnew(size);
	pix->color_d = (unsigned char **)malloc(sizeof(unsigned char *) * size);
	pix->color = (unsigned char **)malloc(sizeof(unsigned char *) * size);
	i = -1;
	while (++i < size)
	{
		pix->color_d[i] = (unsigned char *)malloc(sizeof(unsigned char) * 4);
		pix->color[i] = (unsigned char *)malloc(sizeof(unsigned char) * 4);
		n = -1;
		while (++n < 3)
		{
			pix->color_d[i][n] = 0;
			pix->color[i][n] = 0;
		}
	}
}

t_pix	*create_pix(char **str, int y, int x, int k)
{
	t_pix	*pix;

	pix = (t_pix *)malloc(sizeof(t_pix));
	pix->w = x;
	pix->h = y;
	create_pix_init(pix, y * x);
	create_pix_put(pix, str, k, 0);
	return (pix);
}
