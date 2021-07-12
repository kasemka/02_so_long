#ifndef SOLONG_H
# define SOLONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h> // rdonly funcs
# include <stdio.h> // remove
# include <mlx.h>
// # include  "gnl/get_next_line.h"

// # define empty 0
// # define wall 1
// # define collectible C
// # define exit E
// # define position P

typedef struct s_coordinates
{
	int						x;
	int						y;
	struct s_coordinates	*next;
}				t_coordinates;


typedef struct s_solong{
	void			*mlx;
	void			*win;
	int				map_w;
	int				map_h;
	int				size;
	char			**map;
	t_coordinates	*walls;
	t_coordinates	*coll;
	t_coordinates	*play;
	t_coordinates	*exit;
	void			*img_play;
	void			*img_wall;
	void			*img_coll;
	void			*img_exit;
	void			*img_back;
	int				movements;
}					t_solong;


char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
void	msg_check_argv(void);
void	msg_malloc_fail(void);
void	msg_map_invalid(void);
void	msg_read_error(void);
void	parse(int argc, char **argv, t_solong *params);
int		isinlist(t_coordinates *component, int x, int y);
void	remove_list_srtuct(t_coordinates **component, int x, int y); //remove!!!!!!!!!!
char	*ft_strchr(const char *s, int c);
void	ft_putnbr_fd(int n, int fd);

void printfCoordinates(t_coordinates *stack);

#endif
