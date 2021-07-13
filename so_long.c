#include "so_long.h"

int	main(int argc, char **argv)
{
	t_solong			prm;

	prm.size = 64;
	parse(argc, argv, &prm);
	record_list(&prm);
	prm.movements = 0;
	prm.mlx = mlx_init();
	prm.win = mlx_new_window(prm.mlx, prm.wid * prm.size, \
	prm.hieg * prm.size, "Hey panda!");
	image_init(&prm);
	mlx_hook(prm.win, 17, 1L << 0, ft_buttonpress, &prm);
	mlx_hook(prm.win, 2, 1L << 0, ft_keypress, &prm);
	mlx_loop_hook(prm.mlx, render_map, &prm);
	mlx_loop(prm.mlx);
	return (0);
}
