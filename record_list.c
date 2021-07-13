#include "so_long.h"

void	record_list(t_solong *prm)
{
	int	i;

	i = 0;
	prm->walls = create_list(prm->map, '1');
	prm->coll = create_list(prm->map, 'C');
	prm->play = create_list(prm->map, 'P');
	prm->exit = create_list(prm->map, 'E');
	while (prm->map[i] != NULL)
	{
		free(prm->map[i]);
		prm->map[i] = NULL;
		i++;
	}
	free(prm->map);
}
