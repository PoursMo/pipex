#include "pipex.h"

static void	toggle_quote(int *in_dquote, int *in_squote, char quote)
{
	if (quote == '"')
		*in_dquote = !(*in_dquote);
	else if (quote == '\'')
		*in_squote = !(*in_squote);
}

static int	calculate_string_size(const char *str)
{
	int	size;
	int	in_dquote;
	int	in_squote;

	size = 0;
	in_dquote = 0;
	in_squote = 0;
	while (*str && (!ft_isspace(*str) || in_dquote || in_squote))
	{
		if ((*str == '"' && !in_squote) || (*str == '\'' && !in_dquote))
			toggle_quote(&in_dquote, &in_squote, *str);
		else if (*str == '\\' && !in_squote)
			str++;
		else
			size++;
		str++;
	}
	return (size);
}

static char	*create_string(char **str)
{
	char	*string;
	int		i;
	int		in_dquote;
	int		in_squote;

	string = malloc(sizeof(char) * (calculate_string_size(*str) + 1));
	if (!string)
		return (NULL);
	i = 0;
	in_dquote = 0;
	in_squote = 0;
	while (**str && (!ft_isspace(**str) || in_dquote || in_squote))
	{
		if ((**str == '"' && !in_squote) || (**str == '\'' && !in_dquote))
			toggle_quote(&in_dquote, &in_squote, **str);
		else if (**str == '\\' && !in_squote && (*str)++)
			string[i++] = **str;
		else
			string[i++] = **str;
		(*str)++;
	}
	string[i] = '\0';
	return (string);
}

static int	count_strings(const char *cmd)
{
	int	count;
	int	in_dquote;
	int	in_squote;

	count = 0;
	while (*cmd)
	{
		while (*cmd && ft_isspace(*cmd))
			cmd++;
		if (*cmd && !ft_isspace(*cmd))
		{
			count++;
			in_dquote = 0;
			in_squote = 0;
			while (*cmd && (!ft_isspace(*cmd) || in_dquote || in_squote))
			{
				if ((*cmd == '"' && !in_squote) || (*cmd == '\'' && !in_dquote))
					toggle_quote(&in_dquote, &in_squote, *cmd);
				else if (*cmd == '\\' && !in_squote)
					cmd++;
				cmd++;
			}
		}
	}
	return (count);
}

char	**parse_cmd(char *cmd)
{
	char	**parse;
	int		i;

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
			{
				free_str_arr(parse);
				return (NULL);
			}
			i++;
		}
	}
	parse[i] = NULL;
	return (parse);
}
