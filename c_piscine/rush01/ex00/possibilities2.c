/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possibilities2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpantoja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 12:07:17 by rpantoja          #+#    #+#             */
/*   Updated: 2020/12/07 12:08:10 by rpantoja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "variables.h"

void	reduce_cell_possibilities(int row, int col, int by_row);
void	fill_row_unique_possibility(int row);
void	fill_col_unique_possibility(int col);
int		get_row_pov(int row, int col);
int		get_col_pov(int row, int col);

void	reduce_row_possibilities(int row)
{
	int col;

	col = 0;
	while (col < 4)
	{
		if (g_grid[row][col] != 0)
		{
			col++;
			continue;
		}
		reduce_cell_possibilities(row, col, 1);
		col++;
	}
	fill_row_unique_possibility(row);
}

void	reduce_col_possibilities(int col)
{
	int row;
	int	i;

	row = 0;
	while (row < 4)
	{
		i = 0;
		if (g_grid[row][col] != 0)
		{
			row++;
			continue;
		}
		reduce_cell_possibilities(row, col, 0);
		row++;
	}
	fill_col_unique_possibility(col);
}

void	pov_possibility_elimination(int row, int col, int pov)
{
	int p;

	p = 0;
	while (p < 4)
	{
		if (4 - g_grid_possibilities[row][col][p] + 1 < pov)
		{
			g_grid_possibilities[row][col][p] = 0;
		}
		p++;
	}
}

void	reduce_edge_possibilities(void)
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
			pov_possibility_elimination(row, col, get_col_pov(row, col));
			pov_possibility_elimination(row, col, get_row_pov(row, col));
			col++;
		}
		row++;
	}
}

void	create_grid_possibilities(void)
{
	int row;
	int col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			if (g_grid[row][col] == 0)
			{
				g_grid_possibilities[row][col][0] = 1;
				g_grid_possibilities[row][col][1] = 2;
				g_grid_possibilities[row][col][2] = 3;
				g_grid_possibilities[row][col][3] = 4;
			}
			col++;
		}
		row++;
	}
}
