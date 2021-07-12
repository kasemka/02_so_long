#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# define BUFFER_SIZE 100

size_t			ft_strlen(const char *s);
char			*ft_strchr(const char *s, int c);
char			*ft_strdupc(char *s1, char c);
int				get_next_line(int fd, char **line);


#endif