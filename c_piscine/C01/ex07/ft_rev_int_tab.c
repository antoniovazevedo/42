/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazevedo <aazevedo@students.42lisbo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 00:21:13 by aazevedo          #+#    #+#             */
/*   Updated: 2020/12/02 16:36:27 by aazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
