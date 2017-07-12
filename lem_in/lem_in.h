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
	char 			*input;
	int 			ants;
	int 			**connect;
	int 			n_rooms;
	struct s_room	*rooms;
	int 			start;
	int 			end;
	int 			**way;
	int				n_way;
	int 			*ant;
	char			error;
}					t_lem;

typedef struct		s_room
{
	char			*name;
	int 			x;
	int 			y;
}					t_room;

int			get_next_line(const int fd, char **line);
int		ft_strsplit_len(char **split);
void	ft_strsplit_free(char **split);

#endif