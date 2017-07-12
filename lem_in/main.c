#include "lem_in.h"
#include <stdio.h>
#include <zconf.h>

t_lem	*create_s(void)
{
	t_lem	*lem;

	lem = (t_lem *)malloc(sizeof(t_lem));
	lem->input = NULL;
	lem->ants = -1;
	lem->connect = NULL;
	lem->n_rooms = -1;
	lem->rooms = NULL;
	lem->start = -1;
	lem->end = -1;
	lem->way = NULL;
	lem->n_way = 0;
	lem->error = 0;
	return (lem);
}

char	*strjoin_and_free(char *s1, char *s2)
{
	char *fresh;
	char *ptr;
	char *tmp;

	fresh = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if (fresh)
	{
		tmp = fresh;
		ptr = s1;
		while (*s1)
			*(fresh++) = *(s1++);
		*(fresh++) = '\n';
		ft_strdel(&ptr);
		s1 = NULL;
		while (*s2)
			*(fresh++) = *(s2++);
		*fresh = '\0';
		s2 = NULL;
	}
	return (tmp);
}

void		input(t_lem *lem, char *name)
{
	char *line;

	line = NULL;
	//del this code
	int fd;
	fd = open(name, O_RDONLY, 0);
	//and change FD
	if (get_next_line(fd, &line) == 1)
		if ((lem->ants = ft_atoi(line)) < 0)
			lem->error = 1;
	if (line == NULL)
	{
		lem->error = 1;
		return ;
	}
	lem->input = ft_strdup(line);
	ft_strdel(&line);
	if (lem->error == 1)
		return ;
	while (get_next_line(fd, &line) > 0)
	{
		if (!ft_strlen(line) || line[0] == 'L')
			lem->error = 1;
		lem->input = strjoin_and_free(lem->input, line);
		ft_strdel(&line);
		if (lem->error == 1)
			break ;
	}
}

int 	n_rooms(char **tmp, int i, int n)
{
	char *ptr;

	while (tmp[++i])
	{
		ptr = ft_strchr(tmp[i], ' ');
		if (tmp[i][0] != '#' && ptr != NULL)
			n++;
	}
	return (n);
}

void	room(t_lem *lem, char *tmp, int flag, int r)
{
	char	**str;

	str = ft_strsplit(tmp, ' ');
	if (ft_strsplit_len(str) == 3)
	{
		lem->rooms[r].name = ft_strdup(str[0]);
		lem->rooms[r].x = ft_atoi(str[1]);
		lem->rooms[r].y = ft_atoi(str[2]);
	}
	ft_strsplit_free(str);
	if (flag == 1)
		lem->start = r;
	else if (flag == 2)
		lem->end = r;
}

void	create_rooms(t_lem *lem, int n, int i, int j)
{
	lem->rooms = (t_room *)malloc(sizeof(t_room) * (n));
	lem->connect = (int **)malloc(sizeof(int *) * (n + 1));
	while (++i < n)
	{
		lem->connect[i] = (int *)malloc(sizeof(int) * n);
		j = -1;
		while (++j < n)
		{
			lem->connect[i][j] = 0;
			if (j == i)
				lem->connect[i][j] = -1;
		}
	}
	lem->connect[i] = NULL;
}

void	connect(t_lem *lem, char *str, int i)
{
	char	**tmp;
	int 	a;
	int 	b;

	a = -1;
	b = -1;
	tmp = ft_strsplit(str, '-');
	if (ft_strsplit_len(tmp) == 2)
	{
		while (++i < lem->n_rooms)
		{
			if (ft_strequ(lem->rooms[i].name, tmp[0]))
				a = i;
			else if (ft_strequ(lem->rooms[i].name, tmp[1]))
				b = i;
		}
		if (a != -1 && b != -1)
		{
			lem->connect[a][b] = 1;
			lem->connect[b][a] = 1;
		}
	}
	ft_strsplit_free(tmp);
}

void	filling(t_lem *lem, int i, int r)
{
	char	**tmp;
	char	*ptr;

	tmp = ft_strsplit(lem->input, '\n');
	lem->n_rooms = n_rooms(tmp, -1, 0);
	create_rooms(lem, lem->n_rooms, -1, -1);
	while (tmp[++i])
	{
		ptr = ft_strchr(tmp[i], ' ');
		if (ptr != NULL && tmp[i][0] != '#')
			room(lem, tmp[i], 0, r++);
		else if (ft_strequ(tmp[i], "##start\0"))
			room(lem, tmp[i], 1, r);
		else if (ft_strequ(tmp[i], "##end\0"))
			room(lem, tmp[i], 2, r);
		else
		{
			ptr = ft_strchr(tmp[i], '-');
			if (ptr != NULL)
				connect(lem, tmp[i], -1);
		}
	}
	ft_strsplit_free(tmp);
}

void	ft_delint(int **tmp, int n)
{
	int i;

	i = -1;
	if (tmp && *tmp)
	{
		while (++i < n)
			free(tmp[i]);
		free(tmp);
		tmp = NULL;
	}
}

int 	**create_int(t_lem *lem, int del, int n)
{
	int 	**tmp;
	int 	**ptr;
	int 	i;
	int 	t;

	ptr = NULL;
	if (del == 1)
		ptr = lem->way; //, n - 1);
	tmp = (int **)malloc(sizeof(int *) * n);
	i = -1;
	while (++i < n)
	{
		tmp[i] = (int *)malloc(sizeof(int) * lem->n_rooms);
		t = -1;
		while (++t < lem->n_rooms)
		{
			if (del == 1 && i < n - 1)
				tmp[i][t] = ptr[i][t];
			else
				tmp[i][t] = -1;
			if (t == 0)
				tmp[i][t] = lem->start;
		}
	}
	ft_delint(ptr, n - 1);
	return (tmp);
}

void 	filling_con(t_lem *lem, int i)
{
	int		q;

	q = -1;
	while (++q < lem->n_rooms)
		lem->connect[q][i] = 2;
}

int 	algoritm(t_lem *lem, int k, int n, int f)
{
	int		i;

	if ((n == lem->start && k != 0) || lem->way[f][k] == lem->end)
		return (1);
	i = -1;
	while (++i < lem->n_rooms)
	{
		if (lem->connect[n][i] == 1 && i != lem->start)
		{
			if (k == 0 || i != lem->way[f][k - 1])
			{
				lem->way[f][++k] = i;
				if (i != lem->end)
					filling_con(lem, i);
				if (i == lem->end)
				{
					lem->way = create_int(lem, 1, ++lem->n_way);
					algoritm(lem, 0, lem->start, lem->n_way - 1);
				}
				else if (algoritm(lem, k, i, f))
					return (1);
			}
		}
	}
	return (0);
}

void	free_connect_tab(t_lem *lem, int i, int n)
{
	while (++i < lem->n_rooms)
	{
		n = -1;
		while (++n < lem->n_rooms)
		{
			if (i == 0 && n == lem->start)
				lem->connect[i][n] = lem->ants;
			else
				lem->connect[i][n] = 0;

		}
	}
}

void	finish(t_lem *lem, int a, int n, int i)
{
	ft_printf("%s\n\n", lem->input);

	while (lem->connect[0][lem->end] != lem->ants)
	{
		a = -1;
		while (++a < lem->ants)
		{
			n = -1;
			while (++n < lem->n_way)
			{
				i = -1;
				while (lem->way[n][++i] != lem->end)
				{
					if (lem->way[n][i] >= 0 && lem->ant[i] != lem->end &&
							(lem->connect[0][lem->way[n][i]] == 0 || lem->way[n][i] == lem->end) &&
							lem->ant[i] != 0 )
					{
						lem->connect[0][lem->way[n][i]] -= 1;
						lem->connect[0][lem->way[n][i + 1]] += 1;
						lem->ant[i] = lem->way[n][i];
						printf("L%d - %s", a, lem->rooms[lem->way[n][i]].name);
					}
				}
			}
		}
		printf("\n");

	}
}

void	create_ant(t_lem *lem, int i)
{
	lem->ant = (int *)malloc(sizeof(int) * lem->ants);
	while (++i < lem->ants)
		lem->ant[i] = lem->start;
}

int		main(int ac, char **av)
{
	t_lem	*lem;
	int		res;

	lem = create_s();
	input(lem, av[1]);
	if (lem->error == 1)
	{
		ft_printf("ERROR\n");
		return (EXIT_FAILURE);
	}
	filling(lem, 0, 0);
	lem->way = create_int(lem, 0, ++lem->n_way);
	res = algoritm(lem, 0, lem->start, lem->n_way - 1);
	create_ant(lem, -1);
	free_connect_tab(lem, -1, -1);



	for (int h = 0; h < lem->n_way; ++h) {
		for (int q = 0; q < lem->n_rooms; ++q) {
			printf("%2d", lem->way[h][q]);
		}
		printf("\n");

	}


	for (int k = 0; k < lem->ants; ++k) {
		printf("|%d|", lem->ant[k]);
	}
	printf("\nwtfff\n");




	//del me
	printf("ants = %d, n_rooms = %d, start = %d, end = %d, n_way = %d\n", lem->ants, lem->n_rooms, lem->start, lem->end, lem->n_way);
	int i = -1;
	while (++i < lem->n_rooms)
		printf("|%s||%d||%d| ", lem->rooms[i].name, lem->rooms[i].x, lem->rooms[i].y);
	printf("\n");
	i = -1;
	int j = -1;
	while (++i < lem->n_rooms)
	{
		j = -1;
		while (++j < lem->n_rooms)
			printf("|%2d|", lem->connect[i][j]);
		printf("\n");
	}


	for (int l = 0; l < lem->n_rooms; ++l) {
		printf("name %s, x %d, y %d, i = %d\n", lem->rooms[l].name, lem->rooms[l].x, lem->rooms[l].y, l);
	}
	//stop it





	if (lem->error != 1)
	{
		finish(lem, 0, 0, 0);
	}
	return (EXIT_SUCCESS);
}
