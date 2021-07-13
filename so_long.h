#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx/mlx.h"

typedef struct s_coordinates
{
	int						x;
	int						y;
	struct s_coordinates	*next;
}				t_coordinates;

typedef struct s_solong{
	void			*mlx;
	void			*win;
	int				wid;
	int				hieg;
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

void			parse(int argc, char **argv, t_solong *params);
void			record_list(t_solong *prm);
void			image_init(t_solong *prm);
int				ft_buttonpress(void);
int				ft_keypress(int keycode, t_solong *prm);
int				render_map(t_solong *prm);
void			ft_putnbr_fd(int n, int fd);
int				map_len(int fd_first_read);
size_t			ft_strlen(const char *s);
char			*ft_strchr(const char *s, int c);
char			**ft_split_with_msg(char const *s, char c);
void			check_empty_line(char *line);
t_coordinates	*create_list(char **map, char c);
int				isinlist(t_coordinates *component, int x, int y);
void			remove_list_srtuct(t_coordinates **component, int x, int y);
void			msg_check_argv(void);
void			msg_malloc_fail(void);
void			msg_map_invalid(void);
void			msg_read_error(void);

#endif
