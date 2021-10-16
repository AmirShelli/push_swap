#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
char	*ft_strchr(const char *src, int c);
char	*ft_substr(char const *s, unsigned int start, size_t size);
char	*ft_strmcat(char **s1, char const *s2, int n);

size_t	ft_strlen(const char *str);
int		ft_getline(char **saved, char **line);

#	endif