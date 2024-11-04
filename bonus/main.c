#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	char	*path;

	if (argc < 5)
	{
		ft_putstr_fd("Usage: ./pipex file1 cmd1... cmdn file2\n", 2);
		exit(EXIT_FAILURE);
	}
	path = get_path(envp);
	if(ft_strncmp(argv[1], "here_doc", 8) == 0)
		heredoc(argc, argv, envp, path);
	pipex(argc, argv, envp, path);
}
