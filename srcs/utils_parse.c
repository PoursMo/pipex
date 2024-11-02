#include "pipex.h"

static char	*ft_strndup(const char *s, size_t n)
{
	char	*dup;
	size_t	size;

	if (!s)
		return (NULL);
	if (n > ft_strlen(s))
		size = ft_strlen(s);
	else
		size = n;
	dup = malloc(sizeof(char) * (size + 1));
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s, size + 1);
	return (dup);
}

static int	count_strs(const char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str && *str != c)
		{
			count++;
			if(*str && (*str == '\'' || *str == '\"'))
			{
				str++;
				while (*str && *str != '\'' && *str != '\"')
					str++;
				str++;
			}
			else
				while (*str && *str != c)
					str++;
		}
	}
	return (count);
}

void	free_str_arr(char **split)
{
	int i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

static char	**free_err(char **split, int count)
{
	while (count--)
		free(split[count]);
	free(split);
	return (NULL);
}

char	**ft_parse(const char *str, char c)
{
	char	**split;
	int		i;
	int		size;

	split = malloc(sizeof(char *) * (count_strs(str, c) + 1));
	if (!split)
		return (NULL);
	i = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str && *str != c)
		{
			size = 0;
			if(*str && (*str == '\'' || *str == '\"'))
			{
				size++;
				while (*(str + size) && *(str + size) != '\'' && *(str + size) != '\"')
					size++;
				size++;
			}
			else
				while (*(str + size) && *(str + size) != c)
					size++;
			split[i] = ft_strtrim(ft_strndup(str, size), "\'\"");
			free(ft_strndup(str, size));
			if (!split[i])
				return (free_err(split, i));
			i++;
			str += size;
		}
	}
	return (split[i] = NULL, split);
}