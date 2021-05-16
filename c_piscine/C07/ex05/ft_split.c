#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int i;
	int len;

	i = -1;
	len = 0;
	while (str[++i])
		len++;
	return (len);
}

char **ft_split(char *str, char *charset)
{
	char 	**result;
	int 	i;

	result = (char **) malloc(sizeof(char *) * ft_strlen(str));
	i = 0;

	while (str[i])
	{
		result[0][0] =
	}

	return (result);
}

int	main(void)
{
	char str[] = "linha 1\nlinha 2\nlinha3\n\nlinha5\n";
	char charset[] = "\n.";

	char **result = ft_split(str, charset);

	int i = 0;
	while (i < 2)
	{
		printf("%s\n", result[i]);
		i++;
	}
}
