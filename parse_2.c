#include "so_long.h"

int	map_len(int fd)
{
	int		fd_res;
	int		len;
	char	buf;

	len = 0;
	fd_res = read(fd, &buf, 1);
	while (fd_res > 0)
	{
		len++;
		fd_res = read(fd, &buf, 1);
	}
	if (fd_res < 0)
		msg_read_error();
	if (len == 0)
		msg_map_invalid();
	close(fd);
	return (len);
}

void	check_empty_line(char *line)
{
	int	i;

	i = 1;
	if (ft_strlen(line) < 3)
		msg_map_invalid();
	while (line[i])
	{
		if (line[i - 1] == '\n' && line[i] == '\n')
			msg_map_invalid();
		i++;
	}
}
