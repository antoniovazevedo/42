/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazevedo <aazevedo@students.42lisbo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 01:40:18 by aazevedo          #+#    #+#             */
/*   Updated: 2020/12/14 18:11:13 by aazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' || *s2 != '\0')
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		if (*s1 != '\0')
			s1++;
		if (*s2 != '\0')
			s2++;
	}
	return (0);
}

void	swap(char **tab, int i, int j)
{
	char *value_i;
	char *value_j;

	value_i = tab[i];
	value_j = tab[j];
	tab[i] = value_j;
	tab[j] = value_i;
}

void	sort(char **list, int size)
{
	int i;
	int swaps;

	i = 1;
	swaps = 0;
	while (i < size)
	{
		if (ft_strcmp(list[i], list[i + 1]) > 0)
		{
			swap(&list[0], i, i + 1);
			swaps++;
		}
		i++;
	}
	if (swaps > 0)
		sort(&list[0], size);
}

int		main(int argc, char **argv)
{
	int i;

	sort(argv, argc - 1);
	i = 0;
	while (++i < argc)
	{
		ft_putstr(argv[i]);
		ft_putstr("\n");
	}
}
