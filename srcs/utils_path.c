#include "pipex.h"

char *get_path(char **envp)
{
	int		i;
	char	*path;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = ft_strdup(envp[i] + 5);
			if (!path)
			{
				perror("ft_strdup");
				exit(EXIT_FAILURE);
			}
			return (path);
		}
		i++;
	}
	ft_putstr_fd("PATH not found in envp\n", 2);
	return (NULL);
	// exit(EXIT_FAILURE);
}

static char *make_cmd_path(char *cmd, char *dir)
{
	char *path;
	char *tmp;

	path = ft_strjoin(dir, "/");
	if (!path)
	{
		perror("ft_strjoin");
		exit(EXIT_FAILURE);
	}
	tmp = ft_strjoin(path, cmd);
	if (!tmp)
	{
		perror("ft_strjoin");
		exit(EXIT_FAILURE);
	}
	free(path);
	return (tmp);
}

char *find_cmd_path(char *cmd, char *path)
{
	char	**dirs;
	char	*full_path;
	int		i;

	if(!path)
		return (NULL);
	dirs = ft_split(path, ':');
	if (!dirs)
	{
		perror("ft_split");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (dirs[i])
	{
		full_path = make_cmd_path(cmd, dirs[i]);
		if (!full_path)
		{
			perror("make_cmd_path");
			exit(EXIT_FAILURE);
		}
		if (access(full_path, F_OK) == 0)
		{
			free_str_arr(dirs);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	free_str_arr(dirs);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": command not found\n", 2);
	exit(127);
}