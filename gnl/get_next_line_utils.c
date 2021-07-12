#include "get_next_line.h"

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

char	*ft_strdupc(char *s1, char c)
{
	int		i;
	char	*s2;
	int		len;

	i = 0;
	len = 0;
	while (s1[len] != c && s1[len] != '\0')
		len++;
	s2 = (char *)malloc(len + 1);
	if (s2 == NULL)
		return (NULL);
	while (i < len)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
