#include "pipex.h"

void	try_execve(char *path, char **argv, char **envp)
{
	if (execve(path, argv, envp) == -1)
	{
		perror("execve");
		exit(EXIT_FAILURE);
	}
}