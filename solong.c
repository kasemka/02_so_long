#include "solong.h"

void	image_init(t_solong *prm)
{
	int			widt;
	int			heig;

	prm->img_play = mlx_xpm_file_to_image(prm->mlx, "./baby.xpm", &widt, &heig);
	prm->img_wall = mlx_xpm_file_to_image(prm->mlx, "./hill.xpm", &widt, &heig);
	prm->img_coll = mlx_xpm_file_to_image(prm->mlx, "./tree.xpm", &widt, &heig);
	prm->img_exit = mlx_xpm_file_to_image(prm->mlx, "./ball.xpm", &widt, &heig);
	prm->img_back = mlx_xpm_file_to_image(prm->mlx, "./back.xpm", &widt, &heig);
}

t_coordinates	*create_list(char **map, char c)
{
	int				i;
	int				j;
	t_coordinates	*first;
	t_coordinates	*tmp;

	first = NULL;
	i = 0;
	j = 0;
	while (map[i] != NULL)
	{
		while (map[i][j] != '\0')
		{
			if (map[i][j] == c)
			{
				tmp = malloc(sizeof(t_coordinates));
				if (tmp == NULL)
					msg_malloc_fail();
				tmp->x = j;
				tmp->y = i;
				tmp->next = first;
				first = tmp;
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (first);
}

void	record_list(t_solong *prm)
{
	prm->walls = create_list(prm->map, '1');
	prm->coll = create_list(prm->map, 'C');
	prm->play = create_list(prm->map, 'P');
	prm->exit = create_list(prm->map, 'E');
}

void	render_img(t_solong *prm, void *img, t_coordinates *component)
{
	t_coordinates	*temp;
	int				size;

	temp = component;
	size = prm->size;
	while (temp != NULL)
	{
		mlx_put_image_to_window(prm->mlx, prm->win, img, \
		temp->x * size, temp->y * size);
		temp = temp->next;
	}
}

void	render_back(t_solong *prm)
{
	int				x;
	int				y;
	int				size;

	x = 0;
	y = 0;
	size = prm->size;
	while (x < prm->map_w)
	{
		while (y < prm->map_h)
		{
			mlx_put_image_to_window(prm->mlx, prm->win, prm->img_back, \
			x * size, y * size);
			y++;
		}
		y = 0;
		x++;
	}
}

int	render_map(t_solong *prm)
{
	render_back(prm);
	render_img(prm, prm->img_wall, prm->walls);
	render_img(prm, prm->img_coll, prm->coll);
	render_img(prm, prm->img_play, prm->play);
	render_img(prm, prm->img_exit, prm->exit);
	return (1); // is it correct?
}

void	movement_count(t_solong *prm)
{
	prm->movements++;
	write(1, "current steps: ", 14);
	ft_putnbr_fd(prm->movements, 1);
	write(1, "\n", 1);
}

void	cmd_move(t_solong *prm, int dir)
{
	int		x_new;
	int		y_new;

	x_new = prm->play->x;
	y_new = prm->play->y;
	if (dir == 0)
		x_new = prm->play->x - 1;
	else if (dir == 2)
		x_new = prm->play->x + 1;
	else if (dir == 1)
		y_new = prm->play->y + 1;
	else if (dir == 13)
		y_new = prm->play->y - 1;
	if (x_new >= 0 && x_new < prm->map_w && y_new >= 0 && y_new < prm->map_h)
	{
		if (isinlist(prm->walls, x_new, y_new) == 0)
		{
			prm->play->x = x_new;
			prm->play->y = y_new;
			movement_count(prm);
		}
		if (isinlist(prm->coll, x_new, y_new) == 1)
			remove_list_srtuct(&prm->coll, x_new, y_new);
		if (isinlist(prm->exit, x_new, y_new) == 1 && prm->coll == NULL)
			exit(0);
	}
}

int	ft_buttonpress(void)
{
	exit(0);
}

int	ft_keypress(int keycode, t_solong *prm)
{
	if (keycode == 53)
		exit (0);
	else if (keycode == 0)
		cmd_move(prm, 0);
	else if (keycode == 1)
		cmd_move(prm, 1);
	else if (keycode == 2)
		cmd_move(prm, 2);
	else if (keycode == 13)
		cmd_move(prm, 13);
	return (0);
}

int	main(int argc, char **argv)
{
	t_solong			prm;

	prm.size = 64;
	parse(argc, argv, &prm);
	prm.movements = 0;
	prm.mlx = mlx_init();
	prm.win = mlx_new_window(prm.mlx, prm.map_w * prm.size, \
	prm.map_h * prm.size, "Hey panda!");
	image_init(&prm);
	record_list(&prm);
	mlx_hook(prm.win, 17, 1L << 0, ft_buttonpress, &prm);
	mlx_hook(prm.win, 2, 1L << 0, ft_keypress, &prm);
	mlx_loop_hook(prm.mlx, render_map, &prm);
	mlx_loop(prm.mlx);

/*

*/
	return (0);
}
