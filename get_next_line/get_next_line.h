/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 17:07:34 by sromanet          #+#    #+#             */
/*   Updated: 2017/01/29 20:45:52 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft/libft.h"
# define BUFF_SIZE 32

typedef	struct		s_line
{
	int				fd;
	char			*str;
	struct s_line	*next;
}					t_line;

int					get_next_line(const int fd, char **line);

#endif
