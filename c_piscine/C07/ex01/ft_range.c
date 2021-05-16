#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int i;
	int *tab;

	if (min >= max)
		return (0);
	i = 0;
	tab = (int *)malloc(sizeof(int) * (max - min));
	if (!tab)
		return (0);
	while (min + i < max)
	{
		tab[i] = min + i;
		i++;
	}
	return (tab);
}
