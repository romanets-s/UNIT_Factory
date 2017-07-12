/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 16:47:37 by sromanet          #+#    #+#             */
/*   Updated: 2017/01/28 15:34:10 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_figure
{
	char			*buf;
	char			alpha;
	int				**cord;
	struct s_figure	*next;
	struct s_figure	*prev;
}				t_figure;

t_figure		*ft_new_struct(void);
char			*ft_create_buf(void);
void			ft_insert_list(t_figure *current, char *buf, char alpha);
void			ft_first_lst(t_figure *list, char *buf, char alpha);
void			ft_bzero(void *s, size_t n);
size_t			ft_strlen(const char *s);
t_figure		*ft_validation(int fd, t_figure *list, char *buf, char alpha);
t_figure		*ft_read(int fd, t_figure *list, char *buf, char alpha);
int				ft_check(char *buf);
int				ft_check_figure_two(char *buf, int i, int j);
int				ft_check_figure(char *buf);
int				ft_check_hash_size(char *buf);
int				ft_check_newline(char *buf, int i, int j);
int				ft_check_next_symbol(char s);
int				ft_check_last_symbol(char s);
int				ft_check_point(char *buf);
char			**ft_buf(char *buf);
char			*ft_fill_buf(char *buf);
int				**ft_fill_cord(void);
int				ft_search_hash(char **buf, int **cord, int x, int i);
int				**ft_cord(char **buf, int **cord);
void			ft_del_list(t_figure *lst);
int				ft_list_size(t_figure *list);
void			ft_res_square(t_figure *list);
void			ft_write_square(t_figure *list, char **square, int a, int b);
int				ft_check_square(t_figure *list, char **square, int tab[2],
									int c);
char			**ft_create_square(int c);
int				ft_size_square(t_figure *list);
void			ft_del_square(char **square, int c);
void			ft_putstr(char const *s);
void			ft_del_figure(char alpha, char **square);
int				ft_res_square_new(t_figure *list, int c, char **square);
void			ft_print_result(char **square);

#endif
