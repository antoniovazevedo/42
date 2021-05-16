/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possibilities3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpantoja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 12:09:27 by rpantoja          #+#    #+#             */
/*   Updated: 2020/12/07 12:46:01 by rpantoja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "variables.h"

void	row_possibility_count(int row, int possibilities[5]);
void	col_possibility_count(int col, int possibilities[5]);
int		calculate_unique_possibility(int possibilities[5]);

void	fill_row_unique_possibility(int row)
{
	int col;
	int p;
	int unique_possibility;
	int possibilities[5];

	row_possibility_count(row, possibilities);
	unique_possibility = calculate_unique_possibility(possibilities);
	if (unique_possibility == 0)
		return ;
	col = 0;
	while (col < 4)
	{
		p = 0;
		while (p < 4)
		{
			if (g_grid_possibilities[row][col][p] == unique_possibility)
				g_grid[row][col] = unique_possibility;
			p++;
		}
		col++;
	}
}

void	fill_col_unique_possibility(int col)
{
	int row;
	int p;
	int unique_possibility;
	int possibilities[5];

	col_possibility_count(col, possibilities);
	unique_possibility = calculate_unique_possibility(possibilities);
	if (unique_possibility == 0)
		return ;
	row = 0;
	while (row < 4)
	{
		p = 0;
		while (p < 4)
		{
			if (g_grid_possibilities[row][col][p] == unique_possibility)
				g_grid[row][col] = unique_possibility;
			p++;
		}
		row++;
	}
}
