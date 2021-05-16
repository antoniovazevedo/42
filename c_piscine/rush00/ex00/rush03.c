/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarreto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 13:50:41 by mbarreto          #+#    #+#             */
/*   Updated: 2020/11/28 13:50:47 by mbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	write_edge_line_char(int current_col, int x)
{
	if (current_col == 1)
	{
		ft_putchar('A');
	}
	else if (current_col == x)
	{
		ft_putchar('C');
	}
	else
	{
		ft_putchar('B');
	}
}

void	write_middle_line_char(int current_col, int x)
{
	if (current_col == 1 || current_col == x)
	{
		ft_putchar('B');
	}
	else
	{
		ft_putchar(' ');
	}
}

void	rush(int x, int y)
{
	int current_row;
	int current_col;

	current_row = 1;
	current_col = 1;
	while (current_row <= y)
	{
		current_col = 1;
		while (current_col <= x)
		{
			if (current_row == 1 || current_row == y)
			{
				write_edge_line_char(current_col, x);
			}
			else
			{
				write_middle_line_char(current_col, x);
			}
			current_col++;
		}
		current_row++;
		ft_putchar('\n');
	}
}
