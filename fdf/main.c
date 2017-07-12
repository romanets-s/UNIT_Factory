/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 19:50:57 by sromanet          #+#    #+#             */
/*   Updated: 2017/05/09 19:51:00 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_fun(int key, void *tmp)
{
	t_img *fdf;

	fdf = (t_img *)tmp;
	if (key == 53)
		destroy(fdf);
	if (key == 91)
		rot_x(fdf->pix, 1);
	if (key == 84)
		rot_x(fdf->pix, -1);
	if (key == 86)
		rot_y(fdf->pix, 1);
	if (key == 88)
		rot_y(fdf->pix, -1);
	if (key == 89)
		rot_z(fdf->pix, 1);
	if (key == 92)
		rot_z(fdf->pix, -1);
	if (key == 69)
		zoom(fdf->pix, 1.2);
	if (key == 78)
		zoom(fdf->pix, 0.8);
	if (key == 67)
		change_color(fdf, -1);
	redraw(fdf);
	return (0);
}

void	drr(t_img *fdf)
{
	int (*ptr_fun)(int, void *);

	rot_z(fdf->pix, 10);
	rot_x(fdf->pix, -50);
	rot_y(fdf->pix, 5);
	zoom(fdf->pix, 0.5);
	draw_img(fdf, 0, -1, 0);
	mlx_put_image_to_window(fdf->mlx->mlx, fdf->mlx->win, fdf->mlx->img, 0, 0);
	ptr_fun = &key_fun;
	mlx_hook(fdf->mlx->win, 2, 5, ptr_fun, fdf);
	mlx_loop(fdf->mlx->mlx);
}

int		valid(char **str, int n, int i, int c)
{
	int x;
	int t;

	while (++i < n)
	{
		c = -1;
		t = 0;
		while (str[i][++c] != '\0')
			if (c != 0 && str[i][c - 1] == ' ' && (ft_isdigit(str[i][c])
				|| str[i][c] == '-'))
				t++;
		if (i == 0)
			x = t;
		if (x != t)
			return (-1);
	}
	if (x == 0)
		return (1);
	return (x);
}

void	read_file(t_img *fdf, int fd, int y, char *name)
{
	char	*line;
	char	**str;
	int		x;

	while (get_next_line(fd, &line) > 0)
		str = str_new(str, line, ++y);
	if ((x = valid(str, y, -1, -1)) == -1)
		ft_putstr("Found wrong line length. Exiting.\n");
	else
	{
		fdf = create_img(str, y, x, name);
		drr(fdf);
	}
	close(fd);
}

int		main(int c, char **v)
{
	int		fd;
	t_img	*fdf;

	if (c == 2)
	{
		if ((fd = open(v[1], O_RDONLY, 0)) == -1)
		{
			ft_putstr("error open file\n");
			return (-1);
		}
		fdf = NULL;
		read_file(fdf, fd, 0, v[1]);
	}
	else
		ft_putstr("Usage: ./fdf <filename>\n");
	return (0);
}
