#include "pipex.h"

int main(int argc, char **argv)
{
	if(argc < 5)
	{
		ft_putstr_fd("Usage: ./pipex file1 cmd1... cmdn file2\n", STDERR_FILENO);
		exit(1);
	}
	int fd;

	fd = open(argv[1], O_RDONLY);
	if(fd == -1)
	{
		perror("open");
		exit(1);
	}
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		perror("dup2");
		exit(1);
	}
	if(close(fd) == -1)
	{
		perror("close");
		exit(1);
	}
	fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC);
	if(fd == -1)
	{
		perror("open");
		exit(1);
	}
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		perror("dup2");
		exit(1);
	}
	if(close(fd) == -1)
	{
		perror("close");
		exit(1);
	}
	char **cmd = ft_split(argv[2], ' ');
	if(execve("/bin/grep", cmd, NULL) == -1)
	{
		perror("execve");
		exit(1);
	}
}