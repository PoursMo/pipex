#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

//utils_split
char	**ft_split(const char *str, char c);
char	**free_split(char **split, int count);

//utils_strings
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
void   ft_putstr_fd(char *s, int fd);

#endif