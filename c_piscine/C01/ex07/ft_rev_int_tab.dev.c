/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazevedo <aazevedo@students.42lisbo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 00:21:13 by aazevedo          #+#    #+#             */
/*   Updated: 2020/12/02 16:35:38 by aazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int i;
	int original_int;
	
	i = 0;
	while (i < size / 2)
	{
		original_int = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i - 1] = original_int;
		i++;
	}
}

int	main(void)
{
	int tab[3];
	tab[0] = 1;
	tab[1] = 2;
	tab[2] = 3;

	ft_rev_int_tab(&tab[0], 3);

	int i;
	i = 0;

	while (i < 3)
	{
		printf("%d\n", tab[i]);
		i++;
	}
}
