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

void	handle_pipes(int argc, char **argv, char **envp, char *path)
{
	int		i;
	int		pipe_fds[2];
	int		pid;

	i = 2;
	while (i < argc - 2)
	{
		try_pipe(pipe_fds);
		pid = try_fork();
		if (pid == 0)
		{
			try_close(pipe_fds[0]);
			try_dup2(pipe_fds[1], STDOUT_FILENO);
			try_close(pipe_fds[1]);
			execute_command(argv[i], envp, path);
		}
		try_close(pipe_fds[1]);
		try_dup2(pipe_fds[0], STDIN_FILENO);
		try_close(pipe_fds[0]);
		i++;
	}
	setup_file2(argv[argc - 1]);
	execute_command(argv[i], envp, path);
}

void	pipex(int argc, char **argv, char **envp)
{
	char	*path;

	setup_file1(argv[1]);
	path = get_path(envp);
	handle_pipes(argc, argv, envp, path);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc < 5)
	{
		ft_putstr_fd("Usage: ./pipex file1 cmd1... cmdn file2\n", 2);
		exit(EXIT_FAILURE);
	}
	pipex(argc, argv, envp);
}
