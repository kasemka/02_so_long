#include "so_long.h"

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
