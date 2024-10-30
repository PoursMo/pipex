#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# include <stdint.h>

//utils_split
char	**ft_split(const char *str, char c);
void	**free_split(char **split);

//utils_strings_1
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
void   ft_putstr_fd(char *s, int fd);

//utils_strings_2
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin(const char *str1, const char *str2);


#endif