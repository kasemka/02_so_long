#include "so_long.h"

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
	while (x < prm->wid)
	{
		while (y < prm->hieg)
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
	return (0);
}
