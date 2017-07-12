/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprosian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 14:34:24 by sprosian          #+#    #+#             */
/*   Updated: 2017/01/25 18:37:38 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_figure	*ft_new_struct(void)
{
	t_figure *list;

	list = (t_figure *)malloc(sizeof(t_figure));
	list->next = NULL;
	list->prev = NULL;
	return (list);
}

char		*ft_create_buf(void)
{
	char *buf;

	if (!(buf = (char *)malloc(sizeof(char) * 22)))
		return (NULL);
	ft_bzero(buf, 22);
	return (buf);
}

int			main(int argc, char **argv)
{
	int			fd;
	t_figure	*list;
	char		*buf;
	t_figure	*ptr;

	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY, 0)) == -1)
		{
			write(1, "error\n", 6);
			return (0);
		}
		list = ft_new_struct();
		buf = ft_create_buf();
		if ((ptr = ft_validation(fd, list, buf, 'A')) == NULL)
			write(1, "error\n", 6);
		else
			ft_res_square(ptr);
		return (0);
	}
	else
		write(1, "usage: ./fillit source_file\n", 28);
	return (0);
}
