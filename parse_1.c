#include "so_long.h"

void	check_calculate_size(t_solong *prm)
{
	int	width;
	int	heigh;

	width = ft_strlen(*prm->map);
	heigh = 1;
	while (prm->map[heigh] != NULL)
	{
		if (width != (int)ft_strlen(prm->map[heigh]))
			msg_map_invalid();
		heigh++;
	}
	if (heigh < 3 || width < 3 || heigh * width < 15)
		msg_map_invalid();
	else
	{
		prm->wid = width;
		prm->hieg = heigh;
	}
}

void	check_components(t_solong *prm)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (prm->map[i] != 0)
	{
		while (prm->map[i][j] != 0)
		{
			if (ft_strchr("01CEP", prm->map[i][j]) == NULL)
				msg_map_invalid();
			j++;
		}
		j = 0;
		i++;
	}
}

// check for at least 1 start position, 1 collectible, and 1 exit
void	check_other_comp(t_solong *prm)
{
	int		pos_coll_exit[3];
	int		i;
	int		j;

	i = 0;
	pos_coll_exit[0] = 0;
	pos_coll_exit[1] = 0;
	pos_coll_exit[2] = 0;
	while (prm->map[i] != 0)
	{
		j = 0;
		while (prm->map[i][j])
		{
			if (prm->map[i][j] == 'P')
				pos_coll_exit[0]++;
			else if (prm->map[i][j] == 'C')
				pos_coll_exit[1]++;
			else if (prm->map[i][j] == 'E')
				pos_coll_exit[2]++;
			j++;
		}
		i++;
	}
	if (pos_coll_exit[0] != 1 || pos_coll_exit[1] < 1 || pos_coll_exit[2] != 1)
		msg_map_invalid();
}

void	check_walls(t_solong *prm)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < prm->hieg)
	{
		while (prm->map[i][j] != 0)
		{
			if (i == 0 || i == prm->hieg - 1)
			{
				if (ft_strchr("1", prm->map[i][j]) == NULL)
					msg_map_invalid();
			}
			if (i > 0 && i < prm->hieg - 1 && (j == 0 || j == prm->wid - 1))
			{
				if (ft_strchr("1", prm->map[i][j]) == NULL)
					msg_map_invalid();
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	parse(int argc, char **argv, t_solong *prm)
{
	int		fd;
	int		fd_res;
	char	*line;
	int		len;

	if (argc != 2)
		msg_check_argv();
	fd = open(argv[1], O_RDONLY);
	len = map_len(fd);
	line = malloc(len);
	if (line == NULL)
		msg_malloc_fail();
	fd = open(argv[1], O_RDONLY);
	fd_res = read(fd, line, len);
	close(fd);
	if (fd_res < 0)
		msg_read_error();
	line[len] = '\0';
	check_empty_line(line);
	prm->map = ft_split_with_msg(line, '\n');
	free(line);
	check_calculate_size(prm);
	check_components(prm);
	check_walls(prm);
	check_other_comp(prm);
}
