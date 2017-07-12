/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 16:50:50 by sromanet          #+#    #+#             */
/*   Updated: 2017/01/18 19:29:30 by sprosian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_figure	*ft_read(int fd, t_figure *list, char *buf, char alpha)
{
	int flag;

	flag = 0;
	while (read(fd, buf, 21))
	{
		flag++;
		if (flag == 1)
			ft_first_lst(list, buf, alpha++);
		else
			ft_insert_list(list, buf, alpha++);
		ft_bzero(buf, 22);
	}
	free(buf);
	if (flag == 0)
	{
		free(list);
		return (NULL);
	}
	return (list);
}
