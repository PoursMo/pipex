#include "pipex.h"

void	try_execve(char *path, char **argv, char **envp)
{
	if (execve(path, argv, envp) == -1)
	{
		perror(path);
		exit(EXIT_FAILURE);
	}
}

void	try_waitpid(int pid, int *status, int options)
{
	if (waitpid(pid, status, options) == -1)
	{
		perror("waitpid");
		exit(EXIT_FAILURE);
	}
}
