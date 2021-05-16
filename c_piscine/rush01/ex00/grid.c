/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpantoja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 23:34:13 by rpantoja          #+#    #+#             */
/*   Updated: 2020/12/06 23:35:26 by rpantoja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "variables.h"
#include <unistd.h>

int		get_row_pov(int row, int col);
int		get_col_pov(int row, int col);

void	print_grid(void)
{
	int		row;
	int		col;
	char	c;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			c = g_grid[row][col] + '0';
			write(1, &c, 1);
			if (col < 3)
				write(1, " ", 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}

void	fill_grid_row(int row, int start_col)
{
	int col;
	int i;

	i = 0;
	col = start_col;
	while (i < 4)
	{
		g_grid[row][col] = start_col == 0 ? col + 1 : 4 - col;
		if (start_col == 0)
			col++;
		else
			col--;
		i++;
	}
}

void	fill_grid_col(int col, int start_row)
{
	int i;
	int row;

	i = 0;
	row = start_row;
	while (i < 4)
	{
		g_grid[row][col] = start_row == 0 ? row + 1 : 4 - row;
		if (start_row == 0)
			row++;
		else
			row--;
		i++;
	}
}

void	derive_row_from_pov(int row, int col)
{
	int row_pov;
	int col_pov;

	row_pov = get_row_pov(row, col);
	col_pov = get_col_pov(row, col);
	if (row_pov == 4)
		fill_grid_row(row, col);
	if (col_pov == 4)
		fill_grid_col(col, row);
	if (row_pov == 1 || col_pov == 1)
		g_grid[row][col] = 4;
}

void	derive_from_povs(void)
{
	int row;
	int col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			if ((row == 1 || row == 2) && (col == 1 || col == 2))
			{
				col++;
				continue;
			}
			derive_row_from_pov(row, col);
			col++;
		}
		row++;
	}
}
