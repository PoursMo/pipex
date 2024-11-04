#include "pipex.h"

void	setup_file1(char *file)
{
	int	fd;

	if (access(file, R_OK) == -1)
	{
		perror(file);
		fd = try_open("/dev/null", O_RDONLY, 0);
	}
	else
		fd = try_open(file, O_RDONLY, 0);
	try_dup2(fd, STDIN_FILENO);
	try_close(fd);
}

void	setup_file2(char *file)
{
	int	fd;

	if (access(file, W_OK) == -1 && access(file, F_OK) == 0)
	{
		perror(file);
		exit(EXIT_FAILURE);
	}
	fd = try_open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	try_dup2(fd, STDOUT_FILENO);
	try_close(fd);
}

void	pipex(int argc, char **argv, char **envp, char *path)
{
	int		i;

	setup_file1(argv[1]);
	i = 2;
	while (i < argc - 2)
		handle_command(argv[i++], envp, path);
	setup_file2(argv[argc - 1]);
	execute_command(argv[i], envp, path);
}