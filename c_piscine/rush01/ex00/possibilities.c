/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possibilities.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpantoja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 11:46:18 by rpantoja          #+#    #+#             */
/*   Updated: 2020/12/07 11:46:39 by rpantoja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "variables.h"

void	reduce_cell_possibility(int row, int col, int p, int by_row)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (by_row == 1 && g_grid_possibilities[row][col][p] == g_grid[row][i])
			g_grid_possibilities[row][col][p] = 0;
		else if (by_row == 0 &&
			g_grid_possibilities[row][col][p] == g_grid[i][col])
			g_grid_possibilities[row][col][p] = 0;
		i++;
	}
}

void	reduce_cell_possibilities(int row, int col, int by_row)
{
	int p;
	int possibility_count;
	int possibility;

	p = 0;
	possibility_count = 0;
	while (p < 4)
	{
		reduce_cell_possibility(row, col, p, by_row);
		if (g_grid_possibilities[row][col][p] > 0)
		{
			possibility_count++;
			possibility = g_grid_possibilities[row][col][p];
		}
		p++;
	}
	g_grid[row][col] = possibility_count == 1 ? possibility : g_grid[row][col];
}

void	row_possibility_count(int row, int possibilities[5])
{
	int p;
	int col;

	possibilities[0] = 0;
	possibilities[1] = 0;
	possibilities[2] = 0;
	possibilities[3] = 0;
	possibilities[4] = 0;
	col = 0;
	while (col < 4)
	{
		p = 0;
		while (p < 4)
		{
			if (g_grid_possibilities[row][col][p] > 0)
				possibilities[p + 1]++;
			p++;
		}
		col++;
	}
}

void	col_possibility_count(int col, int possibilities[5])
{
	int p;
	int row;

	possibilities[0] = 0;
	possibilities[1] = 0;
	possibilities[2] = 0;
	possibilities[3] = 0;
	possibilities[4] = 0;
	row = 0;
	while (row < 4)
	{
		p = 0;
		while (p < 4)
		{
			if (g_grid_possibilities[row][col][p] > 0)
				possibilities[p + 1]++;
			p++;
		}
		row++;
	}
}

int		calculate_unique_possibility(int possibilities[5])
{
	int unique_possibility;
	int k;

	k = 0;
	while (k < 5)
	{
		if (possibilities[k] == 1)
			unique_possibility = k;
		k++;
	}
	return (unique_possibility);
}
