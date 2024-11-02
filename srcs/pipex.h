#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>

//utils_parse
char	**ft_parse(const char *str, char c);
void	free_str_arr(char **split);

//utils_path
char *get_path(char **envp);
char *find_cmd_path(char *cmd, char *path);

#endif