#include "push_swap.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int		len;
	size_t	i;

	len = ft_strlen(src);
	if (size == 0)
		return (len);
	i = 0;
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

int	calc_words(char const *s, char c)
{
	int	count;
	int	flag;

	count = 0;
	flag = 0;
	while (*s)
	{
		if (*s != c)
		{
			if (!flag)
			{
				count++;
				flag = 1;
			}
		}
		else
			flag = 0;
		s++;
	}
	return (count);
}

char	*get_word(char const *s, char c)
{
	char	*word;
	int		size;

	size = 0;
	word = NULL;
	while (s[size] && s[size] != c)
		size ++;
	word = (char *)malloc((size + 1) * sizeof(char));
	if (!word)
		return (NULL);
	ft_strlcpy(word, s, size + 1);
	return (word);
}

char	**clean_matrix(char **matrix, int row)
{
	int	i;

	i = 0;
	while (i < row)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**matrix;
	int		words_num;
	int		row;

	words_num = calc_words(s, c);
	matrix = (char **)malloc((words_num + 1) * sizeof(char *));
	if (!matrix)
		return (NULL);
	row = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			matrix[row] = get_word(s, c);
			if (!matrix[row])
				return (clean_matrix(matrix, row));
			row++;
			while (*s && *s != c)
				s++;
		}
	}
	matrix[row] = NULL;
	return (matrix);
}
