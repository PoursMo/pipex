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

void execute_pipes()
{
	
}

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fds[2];
	int		pid;
	int		i;
	char	**cmd;
	char *path;

	if (argc < 5)
	{
		ft_putstr_fd("Usage: ./pipex file1 cmd1... cmdn file2\n", 2);
		exit(EXIT_FAILURE);
	}
	setup_file1(argv[1]);
	path = get_path(envp);
	i = 2;
	while (i < argc - 2)
	{
		try_pipe(pipe_fds);
		pid = try_fork();
		cmd = parse_cmd(argv[i]);
		if (pid == 0)
		{
			try_close(pipe_fds[0]);
			try_dup2(pipe_fds[1], STDOUT_FILENO);
			try_close(pipe_fds[1]);
			if(access(cmd[0], F_OK) == 0)
				try_execve(cmd[0], cmd, envp);
			try_execve(find_cmd_path(cmd[0], path), cmd, envp);
		}
		try_close(pipe_fds[1]);
		try_dup2(pipe_fds[0], STDIN_FILENO);
		try_close(pipe_fds[0]);
		free_str_arr(cmd);
		i++;
	}
	cmd = parse_cmd(argv[i]);
	setup_file2(argv[argc - 1]);
	if(access(cmd[0], F_OK) == 0)
		try_execve(cmd[0], cmd, envp);
	try_execve(find_cmd_path(cmd[0], path), cmd, envp);
}
