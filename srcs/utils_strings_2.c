#include "pipex.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*cs;

	cs = (char *)s;
	while (n--)
		*cs++ = c;
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*new;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	new = malloc(size * nmemb);
	if (!new)
		return (NULL);
	ft_memset(new, 0, nmemb * size);
	return (new);
}

char	*ft_strjoin(const char *str1, const char *str2)
{
	char	*join;
	size_t	size;

	size = ft_strlen(str1) + ft_strlen(str2) + 1;
	join = ft_calloc(sizeof(char), size);
	if (!join)
		return (NULL);
	ft_strlcat(join, str1, size);
	ft_strlcat(join, str2, size);
	return (join);
}