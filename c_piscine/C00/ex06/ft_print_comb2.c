/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazevedo <aazevedo@students.42lisbo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 10:43:13 by aazevedo          #+#    #+#             */
/*   Updated: 2020/12/01 11:03:30 by aazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_number(int d1, int d2)
{
	ft_putchar(d1 + '0');
	ft_putchar(d2 + '0');
}

void	ft_print_numbers(int first, int second)
{
	ft_print_number(first / 10, first % 10);
	ft_putchar(' ');
	ft_print_number(second / 10, second % 10);
	if (first != 98 || second != 99)
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb2(void)
{
	int first;
	int second;

	first = 0;
	second = 0;
	while (first <= 99)
	{
		while (second <= 99)
		{
			if (first == second)
			{
				second++;
				continue;
			}
			ft_print_numbers(first, second);
			second++;
		}
		first++;
		second = first + 1;
	}
}
