/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 20:43:17 by sromanet          #+#    #+#             */
/*   Updated: 2017/07/13 20:43:18 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

# define BUFF_SIZE 1

typedef	struct		s_line
{
	int				fd;
	char			*str;
	struct s_line	*next;
}					t_line;

typedef struct		s_lem
{
	char			*input;
	int				ants;
	int				**connect;
	int				n_rooms;
	struct s_room	*rooms;
	int				start;
	int				end;
	int				**way;
	int				n_way;
	int				*ant;
	char			error;
}					t_lem;

typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
}					t_room;

int					get_next_line(const int fd, char **line);
int					ft_strsplit_len(char **split);
void				ft_strsplit_free(char **split);
void				input(t_lem *lem);
void				input2(t_lem *lem, char *line);
int					n_rooms(char **tmp, int i, int n);
void				room(t_lem *lem, char *tmp, int flag, int r);
void				create_rooms(t_lem *lem, int n, int i, int j);
void				filling(t_lem *lem, int i, int r);
void				filling2(t_lem *lem, char *ptr, char *tmp);
t_lem				*create_s(void);
char				*strjoin_and_free(char *s1, char *s2);
void				ft_delint(int **tmp, int n);
int					**create_int(t_lem *lem, int del, int n);
void				create_ant(t_lem *lem, int i);
void				start_finish(t_lem *lem, int a);
void				finish(t_lem *lem, int a);
void				check_error(t_lem *lem, int n, int i);
int					error(t_lem *lem);
void				connect(t_lem *lem, char *str, int i);
int					algoritm(t_lem *lem, int k, int n, int f);
void				next_step(t_lem *lem, int a, int n, int i);
void				filling_con(t_lem *lem, int i);
void				free_connect_tab(t_lem *lem, int i, int n);

#endif
