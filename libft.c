#include "so_long.h"

size_t	ft_strlen(const char *s)
{
	const char	*ps;

	ps = s;
	while (*ps != '\0')
		ps++;
	return (ps - s);
}

char	*ft_strchr(const char *s, int c)
{
	char	sm;

	sm = (char)c;
	while (*s)
	{
		if (*s == sm)
			return ((char *)s);
		s++;
	}
	if (sm == '\0')
		return ((char *)s);
	return (NULL);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	nums[11];
	int		i;
	int		num;

	i = 0;
	num = n;
	if (n == 0)
		write(fd, "0", 1);
	while (num != 0)
	{
		if (num > 0)
			nums[i] = (num % 10) + 48;
		else
			nums[i] = -(num % 10) + 48;
		i++;
		num = num / 10;
	}
	if (n < 0)
		write(fd, "-", 1);
	i--;
	while (i >= 0)
	{
		write(fd, &nums[i], 1);
		i--;
	}
}
