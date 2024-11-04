#include "pipex.h"

char	*get_path(char **envp)
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
}

static char	*make_cmd_path(char *cmd, char *dir)
{
	char	*path;
	char	*tmp;

	if (dir[ft_strlen(dir) - 1] == '/')
		path = ft_strdup(dir);
	else
		path = ft_strjoin(dir, "/");
	if (!path)
	{
		perror("path");
		exit(EXIT_FAILURE);
	}
	tmp = ft_strjoin(path, cmd);
	free(path);
	if (!tmp)
	{
		perror("ft_strjoin");
		exit(EXIT_FAILURE);
	}
	return (tmp);
}

static void	cmd_not_found(char *cmd)
{
	char	*err;

	err = ft_strjoin(cmd, ": command not found\n");
	if (!err)
	{
		perror("ft_strjoin");
		exit(EXIT_FAILURE);
	}
	write(2, err, ft_strlen(err));
	free(err);
	exit(127);
}

static char	*search_cmd_in_dirs(char *cmd, char **dirs)
{
	int		i;
	char	*full_path;

	i = 0;
	while (dirs[i])
	{
		full_path = make_cmd_path(cmd, dirs[i]);
		if (access(full_path, F_OK) == 0)
		{
			free_str_arr(dirs);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	free_str_arr(dirs);
	cmd_not_found(cmd);
	return (NULL);
}

char	*find_cmd_path(char *cmd, char *path)
{
	char	**dirs;

	if (!path)
		cmd_not_found(cmd);
	dirs = ft_split(path, ':');
	if (!dirs)
	{
		perror("ft_split");
		exit(EXIT_FAILURE);
	}
	return (search_cmd_in_dirs(cmd, dirs));
}
