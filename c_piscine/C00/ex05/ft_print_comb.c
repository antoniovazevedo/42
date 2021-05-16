/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazevedo <aazevedo@students.42lisbo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 21:15:33 by aazevedo          #+#    #+#             */
/*   Updated: 2020/12/01 12:55:32 by aazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_number(char d1, char d2, char d3)
{
	if ((d1 != d2 || d2 != d3) && d2 <= d3)
	{
		write(1, &d1, 1);
		write(1, &d2, 1);
		write(1, &d3, 1);
		if (d1 != '7' || d2 != '8' || d3 != '9')
		{
			write(1, ", ", 2);
		}
	}
}

void	ft_print_comb(void)
{
	char d1;
	char d2;
	char d3;

	d1 = '0';
	while (d1 <= '9')
	{
		d2 = d1 + 1;
		while (d2 <= '9')
		{
			d3 = d2 + 1;
			if (d1 > d2)
			{
				d2++;
				continue;
			}
			while (d3 <= '9')
			{
				ft_print_number(d1, d2, d3);
				d3++;
			}
			d2++;
		}
		d1++;
	}
}
