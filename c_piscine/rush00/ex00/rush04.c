/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazevedo <aazevedo@students.42lisbo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 12:18:05 by aazevedo          #+#    #+#             */
/*   Updated: 2020/11/29 12:28:30 by aazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int g_current_row = 1;
int g_current_col = 1;

void	ft_putchar(char c);
void	write_first_line_char(int x);
void	write_end_line_char(int x);
void	write_middle_line_char(int x);

void	write_line_char(int x, int y)
{
	if (g_current_row == 1)
	{
		write_first_line_char(x);
	}
	else if (g_current_row == y)
	{
		write_end_line_char(x);
	}
	else
	{
		write_middle_line_char(x);
	}
}

void	write_first_line_char(int x)
{
	if (g_current_col == 1)
	{
		ft_putchar('A');
	}
	else if (g_current_col == x)
	{
		ft_putchar('C');
	}
	else
	{
		ft_putchar('B');
	}
}

void	write_end_line_char(int x)
{
	if (g_current_col == 1)
	{
		ft_putchar('C');
	}
	else if (g_current_col == x)
	{
		ft_putchar('A');
	}
	else
	{
		ft_putchar('B');
	}
}

void	write_middle_line_char(int x)
{
	if (g_current_col == 1 || g_current_col == x)
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
	while (g_current_row <= y)
	{
		g_current_col = 1;
		while (g_current_col <= x)
		{
			write_line_char(x, y);
			g_current_col++;
		}
		g_current_row++;
		ft_putchar('\n');
	}
}
