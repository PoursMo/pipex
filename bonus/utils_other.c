#include "pipex.h"

void	free_str_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

int	ft_isspace(int c)
{
	if (c == ' ' || (c >= '\t' && c <= '\r'))
		return (1);
	return (0);
}

void	execute_command(char *cmd, char **envp, char *path)
{
	char	**full_cmd_path;

	full_cmd_path = parse_cmd(cmd);
	if (access(full_cmd_path[0], F_OK) == 0)
		try_execve(full_cmd_path[0], full_cmd_path, envp);
	try_execve(find_cmd_path(full_cmd_path[0], path), full_cmd_path, envp);
}
