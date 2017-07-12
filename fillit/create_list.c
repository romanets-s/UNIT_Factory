/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprosian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 17:32:00 by sprosian          #+#    #+#             */
/*   Updated: 2017/01/11 18:56:01 by sprosian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_insert_list(t_figure *current, char *buf, char alpha)
{
	char		**buffer;
	int			**empty_cord;

	while (current->next != NULL)
		current = current->next;
	current->next = (t_figure *)malloc(sizeof(t_figure));
	(current->next)->prev = current;
	current = current->next;
	buffer = ft_buf(buf);
	current->buf = ft_fill_buf(buf);
	empty_cord = ft_fill_cord();
	current->cord = ft_cord(buffer, empty_cord);
	current->alpha = alpha;
	current->next = NULL;
}

void	ft_first_lst(t_figure *list, char *buf, char alpha)
{
	char	**buffer;
	int		**empty_cord;

	buffer = ft_buf(buf);
	list->buf = ft_fill_buf(buf);
	empty_cord = ft_fill_cord();
	list->cord = ft_cord(buffer, empty_cord);
	list->alpha = alpha;
	list->prev = NULL;
	list->next = NULL;
}
