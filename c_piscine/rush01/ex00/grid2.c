/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpantoja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 11:43:27 by rpantoja          #+#    #+#             */
/*   Updated: 2020/12/07 12:45:12 by rpantoja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "variables.h"

int		get_row_pov(int row, int col);
int		get_col_pov(int row, int col);

void	complete_row(int row)
{
	int col;
	int remaining_count;
	int remaining_col;
	int sum;

	col = 0;
	sum = 0;
	remaining_count = 0;
	while (col < 4)
	{
		if (g_grid[row][col] == 0)
		{
			remaining_count++;
			remaining_col = col;
		}
		sum += g_grid[row][col];
		col++;
	}
	if (remaining_count == 1)
		g_grid[row][remaining_col] = 10 - sum;
}

void	complete_col(int col)
{
	int row;
	int remaining_count;
	int remaining_row;
	int sum;

	row = 0;
	sum = 0;
	remaining_count = 0;
	while (row < 4)
	{
		if (g_grid[row][col] == 0)
		{
			remaining_count++;
			remaining_row = row;
		}
		sum += g_grid[row][col];
		row++;
	}
	if (remaining_count == 1)
		g_grid[remaining_row][col] = 10 - sum;
}

void	complete_grid(void)
{
	int row;
	int col;

	row = 0;
	while (row < 4)
	{
		complete_row(row);
		row++;
	}
	col = 0;
	while (col < 4)
	{
		complete_col(col);
		col++;
	}
}

int		get_row_count(int row)
{
	int max;
	int col;
	int count;

	col = 0;
	count = 0;
	max = g_grid[row][col];
	while (col < 3)
	{
		if (g_grid[row][col + 1] > max)
		{
			count++;
			max = g_grid[row][col + 1];
		}
		if (g_grid[row][col] == 4)
			break ;
		col++;
	}
	return (count);
}

int		is_grid_correct(void)
{
	int row;
	int row1;
	int row2;
	int col;
	int col2;
	int col3;
	int row_pov;
	int col_pov;
	int count;
	int max;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			if (g_grid[row][col] == 0)
				return (0);
			row_pov = get_row_pov(row, col);
			if (row_pov > 0 && 4 - g_grid[row][col] + 1 < row_pov)
				return (0);
			col_pov = get_col_pov(row, col);
			if (col_pov > 0 && 4 - g_grid[row][col] + 1 < col_pov)
				return (0);
			col++;
		}
		count = get_row_count(row);
		row_pov = get_row_pov(row, 0);
		if (count != row_pov - 1)
			return (0);
		col2 = 3;
		count = 0;
		row_pov = get_row_pov(row, 3);
		max = g_grid[row][col2];
		while (col2 >= 1)
		{
			if (g_grid[row][col2 - 1] > max)
			{
				count++;
				max = g_grid[row][col2 - 1];
			}
			if (g_grid[row][col2] == 4)
				break ;
			col2--;
		}
		if (count != row_pov - 1)
			return (0);
		row++;
	}
	col3 = 0;
	while (col3 < 4)
	{
		row1 = 0;
		count = 0;
		col_pov = get_col_pov(0, col3);
		max = g_grid[row1][col3];
		while (row1 < 3)
		{
			if (g_grid[row1 + 1][col3] > max)
			{
				count++;
				max = g_grid[row1 + 1][col3];
			}
			if (g_grid[row1][col3] == 4)
				break ;
			row1++;
		}
		if (count != col_pov - 1)
			return (0);
		row2 = 3;
		count = 0;
		col_pov = get_col_pov(3, col3);
		max = g_grid[row2][col3];
		while (row2 >= 1)
		{
			if (g_grid[row2 - 1][col3] > max)
			{
				count++;
				max = g_grid[row2 - 1][col3];
			}
			if (g_grid[row2][col3] == 4)
				break ;
			row2--;
		}
		if (count != col_pov - 1)
			return (0);
		col3++;
	}
	return (1);
}
