#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include "get_next_line.h"

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>

//utils_parse
char	**parse_cmd(char *cmd);

//utils_path
char	*get_path(char **envp);
char	*find_cmd_path(char *cmd, char *path);

//utils_other
void	free_str_arr(char **arr);
int		ft_isspace(int c);
void	execute_command(char *cmd, char **envp, char *path);

//utils_tries_1
int		try_open(char *file, int flags, mode_t mode);
void	try_close(int fd);
void	try_dup2(int oldfd, int newfd);
void	try_pipe(int pipefd[2]);
int		try_fork(void);

//utils_tries_2
void	try_execve(char *path, char **argv, char **envp);
void	try_waitpid(int pid, int *status, int options);

#endif