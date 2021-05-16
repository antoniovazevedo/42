/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazevedo <aazevedo@students.42lisbo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 21:07:18 by aazevedo          #+#    #+#             */
/*   Updated: 2020/12/01 12:28:48 by aazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(int *tab, int i, int j)
{
	int value_i;
	int value_j;

	value_i = tab[i];
	value_j = tab[j];
	tab[i] = value_j;
	tab[j] = value_i;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int i;
	int swaps;

	i = 0;
	swaps = 0;
	while (i <= size - 2)
	{
		if (tab[i] > tab[i + 1])
		{
			swap(&tab[0], i, i + 1);
			swaps++;
		}
		i++;
	}
	if (swaps > 0)
	{
		ft_sort_int_tab(&tab[0], size);
	}
}
