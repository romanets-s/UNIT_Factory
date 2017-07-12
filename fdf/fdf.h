/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 22:11:28 by sromanet          #+#    #+#             */
/*   Updated: 2017/05/09 22:11:31 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# define BUFF_SIZE 6144
# include <stdio.h>
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

typedef struct		s_pix
{
	int				w;
	int				h;
	int				size;
	float			*x_def;
	float			*y_def;
	float			*z_def;
	float			*x;
	float			*y;
	float			*z;
	unsigned char	**color_d;
	unsigned char	**color;
}					t_pix;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	int				w_px;
	int				h_px;
	int				bpp;
	int				size_l;
	int				e;
	char			*str;
}					t_mlx;

typedef struct		s_img
{
	int				width;
	int				height;
	int				k;
	struct s_mlx	*mlx;
	struct s_pix	*pix;
	int				lengthx;
	int				lengthy;
	int				d;
	int				tmp;
	double			len;
	int				x;
	int				y;

}					t_img;

typedef	struct		s_line
{
	int				fd;
	char			*str;
	struct s_line	*next;
}					t_line;

int					get_next_line(const int fd, char **line);
void				rot_z(t_pix *pix, float r);
void				rot_y(t_pix *pix, float r);
void				rot_x(t_pix *pix, float r);
void				zoom(t_pix *pix, float zoom);
char				**str_new(char **str, char *line, int n);
float				*floatnew(int n);
int					ft_dif(float p1, float p2);
int					ft_abs(int a);
t_img				*create_img(char **str, int y, int x, char *name);
t_mlx				*create_mlx(int y, int x, int k, char *name);
t_pix				*create_pix(char **str, int y, int x, int k);
void				create_pix_init(t_pix *pix, int size);
void				create_pix_put(t_pix *pix, char **str, int k, int xx);
void				draw_img(t_img *fdf, int n, int yi, int xx);
void				draw_img_help(t_img *fdf, int n, int i);
void				line(t_img *fdf, int p1, int p2);
void				line_x(t_img *fdf, int p1, int p2, int l);
void				line_y(t_img *fdf, int p1, int p2, int l);
void				freestr(char **str, int n, int i, int z);
void				change_color(t_img *fdf, int i);
void				read_file(t_img *fdf, int fd, int y, char *name);
int					valid(char **str, int n, int i, int c);
void				drr(t_img *fdf);
int					key_fun(int key, void *tmp);
void				color(t_pix *pix, char *c, int n, int i);
void				color_copy(t_pix *pix, int n, int i);
void				freeall(t_img *fdf, int i);
void				destroy(t_img *fdf);
void				redraw(t_img *fdf);

#endif
