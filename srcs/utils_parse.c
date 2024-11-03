#include "pipex.h"

static char	**free_split(char **split, int count)
{
	while (count--)
		free(split[count]);
	free(split);
	return (NULL);
}

int calculate_string_size(const char *str)
{
	int size = 0;
	int in_double_quote = 0;
	int in_single_quote = 0;

	while (*str && (!ft_isspace(*str) || (ft_isspace(*str) && in_double_quote) || (ft_isspace(*str) && in_single_quote)))
	{
		if (*str == '"' && !in_single_quote)
		{
			str++;
			in_double_quote = !in_double_quote;
		}
		else if (*str == '\'' && !in_double_quote)
		{
			str++;
			in_single_quote = !in_single_quote;
		}
		else if (*str == '\\' && !in_single_quote)
			str++;
		else
			size++;
		str++;
	}
	return (size);
}

char *create_string(char **str)
{
	char *string;
	int i;
	int in_double_quote;
	int in_single_quote;

	string = malloc(sizeof(char) * (calculate_string_size(*str) + 1));
	if (!string)
		return (NULL);
	i = 0;
	in_double_quote = 0;
	in_single_quote = 0;
	while (**str && (!ft_isspace(**str) || (ft_isspace(**str) && in_double_quote) || (ft_isspace(**str) && in_single_quote)))
	{
		if(**str == '"' && !in_single_quote)
			in_double_quote	= !in_double_quote;
		else if(**str == '\'' && !in_double_quote)
			in_single_quote = !in_single_quote;
		else if(**str == '\\' && !in_single_quote)
		{
			(*str)++;
			string[i] = **str;
			i++;
		}
		else
		{
			string[i] = **str;
			i++;
		}
		(*str)++;
	}
	string[i] = '\0';
	return (string);
}

int count_strings(const char *cmd)
{
	int count = 0;
	int in_double_quote = 0;
	int in_single_quote = 0;

	while (*cmd)
	{
		while (*cmd && ft_isspace(*cmd))
			cmd++;
		if (*cmd && !ft_isspace(*cmd))
		{
			count++;
			while (*cmd && (!ft_isspace(*cmd) || (ft_isspace(*cmd) && in_double_quote) || (ft_isspace(*cmd) && in_single_quote)))
			{
				if (*cmd == '"' && !in_single_quote)
				{
					cmd++;
					in_double_quote = !in_double_quote;
				}
				else if (*cmd == '\'' && !in_double_quote)
				{
					cmd++;
					in_single_quote = !in_single_quote;
				}
				else if (*cmd == '\\' && !in_single_quote)
					cmd++;
				cmd++;
			}
		}
	}
	return count;
}

char **parse_cmd(char *cmd)
{
	char **parse;
	int i;

	parse = malloc(sizeof(char *) * (count_strings(cmd) + 1));
	if (!parse)
		return (NULL);
	i = 0;
	while (*cmd)
	{
		while (*cmd && ft_isspace(*cmd))
			cmd++;
		if (*cmd && !ft_isspace(*cmd))
		{
			parse[i] = create_string(&cmd);
			if (!parse[i])
				return (free_split(parse, i));
			i++;
		}
	}
	parse[i] = NULL;
	return (parse);
}