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
