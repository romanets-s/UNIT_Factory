/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 22:00:21 by sromanet          #+#    #+#             */
/*   Updated: 2017/06/11 04:27:39 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

# define BUFF_SIZE 164

typedef	struct		s_line
{
	int				fd;
	char			*str;
	struct s_line	*next;
}					t_line;

typedef struct		s_fil
{
	int				fd;
	int				start;
	int				error;
	int				player;
	char			uc;
	char			lc;
	char			ouc;
	char			olc;
	int				size_mx;
	int				size_my;
	int				size_px;
	int				size_py;
	char			**piece;
	long int		value;
	int				pozx;
	int				pozy;
	char			**map;
	int				**koef;
	int				k;
	int				n;
}					t_fil;

int					get_next_line(const int fd, char **line);
int					ft_strsplit_len(char **split);
void				ft_strsplit_free(char **split);
void				filler_init(t_fil *f);
void				filler_vm(t_fil *f);
void				creat_map(t_fil *f, int n);
int					**new_koef(int y, int x, int n, int i);
void				miss_two_line(t_fil *f);
int					ft_pos(int n);
int					kpoint(t_fil *f, int ym, int xm, int k);
void				fill_koef(t_fil *f, int y, int x);
void				new_piece(t_fil *f, int py);
void				fill_map(t_fil *f, int my, int k);
int					search_p(t_fil *f, int my, int mx, int p);
long int			value(t_fil *f, int my, int mx, long int v);
void				search(t_fil *f, int y, int x, long int v);

#endif
