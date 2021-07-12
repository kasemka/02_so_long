#include "solong.h"

// void	msg_error(void)
// {
// 	write(2, "Error\n", 6);
// 	exit(EXIT_FAILURE);
// }

void	msg_malloc_fail(void)
{
	write(2, "malloc fail\n", 12);
	exit(EXIT_FAILURE);
}

void	msg_check_argv(void)
{
	write(1, "check arguments and try again\n", 30);
	exit(EXIT_FAILURE);
}

void	msg_map_invalid(void)
{
	write(1, "Error\nMap is invalid\n", 22);
	exit(EXIT_FAILURE);
}

void	msg_read_error(void)
{
	write(2, "Read error\n", 6);
	exit(EXIT_FAILURE);
}