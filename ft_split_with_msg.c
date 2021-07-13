#include "so_long.h"

static int	ft_rowlen(const char *s, char c)
{
	int	i;

	i = 0;
	while (*s != '\0' && *s != c)
	{
		s++;
		i++;
	}
	return (i);
}

static char	*strdupc(const char *s1, char c)
{
	int		i;
	char	*s2;
	int		len;

	i = 0;
	len = ft_rowlen(s1, c);
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

static int	ft_chrnum(char const *s, char c)
{
	int	n;
	int	j;

	n = 0;
	j = 0;
	if (*s == '\0')
		return (0);
	while (s[j] == c && s[j])
		j++;
	while (s[j])
	{
		if ((s[j] == c) && (s[j + 1] != c))
			n++;
		j++;
	}
	if (s[j - 1] != c)
		n++;
	return (n);
}

char	**ft_free_malloc(char **snew, int i)
{
	while (i >= 0)
	{
		free(snew[i]);
		i--;
	}
	free(snew);
	msg_malloc_fail();
	return (NULL);
}

char	**ft_split_with_msg(char const *s, char c)
{
	char		**str;
	int			rows;
	int			i;

	i = 0;
	rows = ft_chrnum(s, c);
	str = malloc(sizeof(char *) * (rows + 1));
	if (!str)
		msg_malloc_fail();
	while (i < rows)
	{
		while (*s == c && *s)
			s++;
		str[i] = strdupc(s, c);
		if (str[i] == NULL)
			return (ft_free_malloc(str, i));
		while (*s != c && *s)
			s++;
		i++;
	}
	str[i] = 0;
	return (str);
}
