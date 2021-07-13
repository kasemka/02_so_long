#include "so_long.h"

void	movement_count(t_solong *prm)
{
	prm->movements++;
	write(1, "current steps: ", 14);
	ft_putnbr_fd(prm->movements, 1);
	write(1, "\n", 1);
}

void	cmd_move(t_solong *prm, int dir)
{
	int		x_y[2];

	x_y[0] = prm->play->x;
	x_y[1] = prm->play->y;
	if (dir == 0)
		x_y[0] = prm->play->x - 1;
	else if (dir == 2)
		x_y[0] = prm->play->x + 1;
	else if (dir == 1)
		x_y[1] = prm->play->y + 1;
	else if (dir == 13)
		x_y[1] = prm->play->y - 1;
	if (x_y[0] >= 0 && x_y[0] < prm->wid && x_y[1] >= 0 && x_y[1] < prm->hieg)
	{
		if (isinlist(prm->walls, x_y[0], x_y[1]) == 0)
		{
			prm->play->x = x_y[0];
			prm->play->y = x_y[1];
			movement_count(prm);
		}
		if (isinlist(prm->coll, x_y[0], x_y[1]) == 1)
			remove_list_srtuct(&prm->coll, x_y[0], x_y[1]);
		if (isinlist(prm->exit, x_y[0], x_y[1]) == 1 && prm->coll == NULL)
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
