#include "pipex.h"

void heredoc(int argc, char **argv, char **envp, char *path)
{
	char *line;
	int fds[2];

	line = get_next_line(STDIN_FILENO);
	try_pipe(fds);
	while(line)
	{
		write(fds[1], line, ft_strlen(line));
		if(ft_strncmp(line, argv[2], ft_strlen(line) - 1) == 0)
			break;
		free(line)
		line = get_next_line(STDIN_FILENO);
	}
	try_close(fds[1]);
	try_dup2(fds[0], STDIN_FILENO);
	try_close(fds[0]);
	handle_command(argv[3], envp, path);
	setup_file2(argv[argc - 1]);
	execute_command(argv[argc - 2], envp, path);
}