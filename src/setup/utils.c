#include "../../include/cubed.h"

size_t	ft_strlen(const char *s)
{
	size_t	length;
	char	*string;

	length = 0;
	if (s == NULL)
		return (0);
	string = (char *)s;
	while (string[length])
		length++;
	return (length);
}

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

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	index;
	char	*destination;
	char	*source;

	destination = (char *)dst;
	source = (char *)src;
	index = 0;
	if (destination == 0 && source == 0 && n > 0)
		return (0);
	while (index < n)
	{
		destination[index] = source[index];
		index++;
	}
	return (dst);
}

char *ft_strjoin(const char *s1, const char *s2)
{
    if (s1 == NULL && s2 == NULL)
        return NULL;
	

    size_t len1 = (s1 != NULL) ? strlen(s1) : 0;
    size_t len2 = (s2 != NULL) ? strlen(s2) : 0;
    size_t total_len = len1 + len2;

    char *new_string = (char *)malloc(sizeof(char) * (total_len + 1));
    if (new_string == NULL)
    {
        perror("malloc failed in ft_strjoin");
        exit(EXIT_FAILURE);
    }

    if (s1 != NULL)
        ft_memcpy(new_string, s1, len1);
    if (s2 != NULL)
    ft_memcpy(new_string + len1, s2, len2);
    new_string[total_len] = '\0';
    return new_string;
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

