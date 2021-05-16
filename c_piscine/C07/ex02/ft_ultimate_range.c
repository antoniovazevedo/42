/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazevedo <aazevedo@students.42lisbo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 22:37:58 by aazevedo          #+#    #+#             */
/*   Updated: 2020/12/15 22:38:13 by aazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int i;
	int size;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	i = 0;
	size = max - min;
	*range = malloc(sizeof(int) * size);
	if (!*range)
		return (-1);
	while (min + i < max)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (size);
}
