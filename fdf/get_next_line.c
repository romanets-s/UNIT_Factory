/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 17:09:35 by sromanet          #+#    #+#             */
/*   Updated: 2017/01/29 20:45:44 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char		*ft_new_strjoin(char *s1, char const *s2)
{
	char *fresh;
	char *ptr;
	char *tmp;

	tmp = NULL;
	fresh = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (fresh)
	{
		tmp = fresh;
		if (s1)
		{
			ptr = s1;
			while (*s1)
				*(fresh++) = *(s1++);
			free(ptr);
			s1 = NULL;
		}
		if (s2)
			while (*s2)
				*(fresh++) = *(s2++);
		*fresh = '\0';
	}
	return (tmp);
}

static int		ft_next_line(char **line, t_line *lst, char *buf)
{
	char *ptr;
	char *new;

	ptr = NULL;
	if (!lst->str || (!(*lst->str) && !(*buf)))
		return (0);
	free(buf);
	if ((ptr = ft_strchr(lst->str, '\n')))
	{
		*ptr = '\0';
		*line = ft_strdup(lst->str);
		new = ft_strdup(ptr + 1);
		free(lst->str);
		lst->str = new;
		ptr = NULL;
		return (1);
	}
	else
	{
		*line = ft_strdup(lst->str);
		free(lst->str);
		lst->str = NULL;
		return (1);
	}
	return (0);
}

static t_line	*ft_create_new_list(t_line *lst, const int fd)
{
	t_line *tmp;

	tmp = (t_line *)malloc(sizeof(t_line));
	tmp->fd = fd;
	tmp->str = NULL;
	tmp->next = lst;
	lst = tmp;
	return (lst);
}

int				get_next_line(const int fd, char **line)
{
	static t_line	*lst = NULL;
	t_line			*tmp;
	char			*buf;
	int				n;

	buf = ft_strnew(BUFF_SIZE);
	if ((n = read(fd, buf, 0)) < 0)
		return (-1);
	tmp = lst;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (ft_next_line(line, tmp, buf) ? 1 : 0);
		tmp = tmp->next;
	}
	if (!tmp)
		lst = ft_create_new_list(lst, fd);
	while ((n = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[n] = '\0';
		lst->str = ft_new_strjoin(lst->str, buf);
	}
	if (ft_next_line(line, lst, buf))
		return (1);
	return (0);
}
