#include "solong.h"

int	map_len(int fd_first_read)
{
	int		fd_res;
	int		len;
	char	buf;

	len = 0;
	fd_res = read(fd_first_read, &buf, 1);
	while (fd_res > 0)
	{
		len++;
		fd_res = read(fd_first_read, &buf, 1);
	}
	if (fd_res < 0)
		msg_read_error();
	if (len == 0)
		msg_map_invalid();
	return (len);
}

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
		prm->map_w = width;
		prm->map_h = heigh;
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
	j = 0;
	pos_coll_exit[0] = 0;
	pos_coll_exit[1] = 0;
	pos_coll_exit[2] = 0;
	while (prm->map[i] != 0)
	{
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
		j = 0;
		i++;
	}
	if (pos_coll_exit[0] == 0 || pos_coll_exit[1] == 0 || pos_coll_exit[2] == 0)
		msg_map_invalid();
}

void	check_walls(t_solong *prm)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < prm->map_h)
	{
		while (prm->map[i][j] != 0)
		{
			if (i == 0 || i == prm->map_h - 1)
			{
				if (ft_strchr("1", prm->map[i][j]) == NULL)
					msg_map_invalid();
			}
			if (i > 0 && i < prm->map_h - 1 && (j == 0 || j == prm->map_w - 1))
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
	int		fd_first_read;
	int		fd_second_read;
	int		fd_res;
	char	*line;
	int		len;

	if (argc != 2)
		msg_check_argv();
	fd_first_read = open(argv[1], O_RDONLY);
	fd_second_read = open(argv[1], O_RDONLY);
	len = map_len(fd_first_read);
	line = malloc(len);
	if (line == NULL)
		msg_malloc_fail();
	fd_res  = read(fd_second_read, line, len);
	if (fd_res < 0)
		msg_read_error();
	line[len] = '\0';
	prm->map = ft_split(line, '\n');
	if (prm->map == NULL)
		msg_malloc_fail();
	check_calculate_size(prm);
	check_components(prm);
	check_walls(prm);
	check_other_comp(prm);
}
