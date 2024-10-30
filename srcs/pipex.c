#include "pipex.h"

int try_open(char *file, int flags, mode_t mode)
{
	int fd;

	fd = open(file, flags, mode);
	if(fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void try_close(int fd)
{
	if(close(fd) == -1)
	{
		perror("close");
		exit(EXIT_FAILURE);
	}
}

void try_dup2(int oldfd, int newfd)
{
	if(dup2(oldfd, newfd) == -1)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
}

void try_pipe(int pipefd[2])
{
	if(pipe(pipefd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
}

int try_fork()
{
	int pid;

	pid = fork();
	if(pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	return (pid);
}

void try_execve(char *path, char **argv, char **envp)
{
	if(execve(path, argv, envp) == -1)
	{
		perror("execve");
		exit(EXIT_FAILURE);
	}
}

void setup_file1(char *file)
{
	int fd;

	fd = try_open(file, O_RDONLY, 0);
	try_dup2(fd, STDIN_FILENO);
	try_close(fd);
}

void setup_file2(char *file)
{
	int fd;

	fd = try_open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	try_dup2(fd, STDOUT_FILENO);
	try_close(fd);
}

int main(int argc, char **argv)
{
	int pipe_fds[2];
	
	if(argc < 5)
	{
		ft_putstr_fd("Usage: ./pipex file1 cmd1... cmdn file2\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	setup_file1(argv[1]);

	int i = 2;
	while(i < argc - 2)
	{
		try_pipe(pipe_fds);
		int pid = try_fork();
		if(pid == 0)
		{
			try_close(pipe_fds[0]);
			try_dup2(pipe_fds[1], STDOUT_FILENO);
			try_close(pipe_fds[1]);
			char **cmd = ft_split(argv[i], ' ');						//MALLOC
			try_execve(ft_strjoin("/bin/", cmd[0]), cmd, NULL);			//MALLOC
		}
		try_close(pipe_fds[1]);
		try_dup2(pipe_fds[0], STDIN_FILENO);
		try_close(pipe_fds[0]);
		i++;
	}
	setup_file2(argv[argc - 1]);
	char **cmd = ft_split(argv[3], ' ');						//MALLOC
	try_execve(ft_strjoin("/bin/", cmd[0]), cmd, NULL);			//MALLOC
}