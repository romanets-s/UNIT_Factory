/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprosian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 19:08:30 by sprosian          #+#    #+#             */
/*   Updated: 2017/01/25 23:05:05 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_check_next_symbol(char s)
{
	if (s == '\n')
		return (0);
	else
		return (1);
}

int			ft_check_last_symbol(char s)
{
	if (s == '\0')
		return (0);
	else
		return (1);
}

int			ft_check(char *buf)
{
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	while (i < 20)
	{
		if (buf[i] == '.' || buf[i] == '#' || buf[4] == '\n' ||
			buf[9] == '\n' || buf[14] == '\n' || buf[19] == '\n')
			i++;
		else
		{
			flag = 1;
			break ;
		}
	}
	if (flag == 0)
	{
		flag = ft_check_hash_size(buf) + ft_check_newline(buf, 0, 0) +
			ft_check_figure(buf) + ft_check_point(buf);
	}
	if (flag > 0)
		return (1);
	return (0);
}

t_figure	*ft_validation(int fd, t_figure *list, char *buf, char alpha)
{
	t_figure	*ptr;
	t_figure	*lst;
	int			i;

	if (!(ptr = ft_read(fd, list, buf, alpha)))
		return (NULL);
	if (ft_list_size(ptr) > 26)
	{
		ft_del_list(ptr);
		return (NULL);
	}
	i = 0;
	lst = ptr;
	while (ptr->next != NULL)
	{
		i = i + ft_check(ptr->buf);
		i = i + ft_check_next_symbol(ptr->buf[20]);
		ptr = ptr->next;
	}
	i = i + ft_check(ptr->buf);
	i = i + ft_check_last_symbol(ptr->buf[20]);
	if (i == 0)
		return (lst);
	ft_del_list(lst);
	return (NULL);
}
