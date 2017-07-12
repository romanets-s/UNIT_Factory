/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprosian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 19:51:58 by sprosian          #+#    #+#             */
/*   Updated: 2017/01/18 18:43:09 by sprosian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_del_list(t_figure *lst)
{
	int i;

	while (lst != NULL)
	{
		free(lst->buf);
		i = -1;
		while (++i < 2)
			free(lst->cord[i]);
		free(lst->cord);
		if (lst->next == NULL)
		{
			free(lst);
			return ;
		}
		lst = lst->next;
		free(lst->prev);
	}
	return ;
}
