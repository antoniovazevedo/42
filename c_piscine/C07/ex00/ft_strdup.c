#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char *ptr;
	int i;
	int len;
	
	len = 0;
	while (src[len])
		len++;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (0);
	i = 0;
	while (src[i])
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
