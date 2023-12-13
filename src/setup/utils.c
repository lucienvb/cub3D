#include "../../include/cubed.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	index;

	index = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	if (dstsize > 0)
	{
		while ((dstsize - 1) > index && src[index])
		{
			dst[index] = src[index];
			index++;
		}
	}
	dst[index] = '\0';
	return (ft_strlen(src));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	index1;
	size_t	index2;
	size_t	lenght;
	char	*new_string;

	lenght = ft_strlen(s1) + ft_strlen(s2);
	new_string = malloc(sizeof(char) * (lenght + 1));
	if (!new_string)
		return (NULL);
	index1 = 0;
	while (s1[index1])
	{
		new_string[index1] = s1[index1];
		index1++;
	}
	index2 = 0;
	while (s2[index2])
	{
		new_string[index1 + index2] = s2[index2];
		index2++;
	}
	new_string[index1 + index2] = '\0';
	return (new_string);
}

size_t	ft_strlen(const char *s)
{
	size_t	lenght;
	char	*string;

	lenght = 0;
	string = (char *)s;
	if (s == NULL)
		return (0);
	while (string[lenght])
		lenght++;
	return (lenght);
}

char	*ft_strdup(const char *s1)
{
	size_t	index;
	char	*new_string;

	index = 0;
	new_string = malloc (sizeof(char) * ft_strlen(s1) + 1);
	if (!new_string)
		return (NULL);
	while (s1[index])
	{
		new_string[index] = s1[index];
		index++;
	}
		new_string[index] = '\0';
	return (new_string);
	free (new_string);
}


char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*sub_string;
	const unsigned int	string_length = ft_strlen(s);
	size_t				index;

	index = 0;
	if (start > string_length || len == 0)
		return (ft_strdup(""));
	if (start + len >= string_length)
		len = string_length - start;
	sub_string = malloc (sizeof(char) * (len + 1));
	if (!sub_string)
		return (NULL);
	while (index < len && s[start + index])
	{
		sub_string[index] = s[start + index];
		index++;
	}		
	sub_string[index] = '\0';
	return (sub_string);
	free (sub_string);
}

static int	count_words(char const *string, char separator)
{
	int	count;

	count = 0;
	while (*string)
	{
		if (*string != separator)
		{
			while (*string != separator && *string)
				string++;
			count++;
		}
		else if (*string == separator && *string)
			string++;
	}
	return (count);
}

static int	free_split(char **split, int index)
{
	while (index-- > 0)
		free(split[index]);
	free(split);
	return (1);
}

static int	create_split(const char *string, char separator, char **split)
{
	size_t	start;
	size_t	end;
	int		index;

	start = 0;
	end = 0;
	index = 0;
	while (string[start])
	{
		if (string[start] != separator)
		{
			end = start;
			while (string[end] != separator && string[end])
				end++;
			split[index] = ft_substr(string, start, (end - start));
			if (!split[index])
				return (free_split(split, index));
			index++;
			start = end;
		}
		if (string[start] == separator && string[start])
			start++;
	}
	split[index] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	if (create_split(s, c, split) == 1)
		return (NULL);
	return (split);
}

