/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpantoja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 23:30:28 by rpantoja          #+#    #+#             */
/*   Updated: 2020/12/06 23:33:24 by rpantoja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "variables.h"
#include "pov.h"
#include "possibilities.h"
#include "possibilities2.h"
#include "possibilities3.h"
#include "grid.h"
#include "grid2.h"

int g_grid[4][4] = {
	{0, 0, 0, 0},
	{0, 0, 0, 0},
	{0, 0, 0, 0},
	{0, 0, 0, 0}
};
int g_povs_by_row[4][2];
int g_povs_by_col[4][2];
int g_grid_possibilities[4][4][4];

int		solve(void)
{
	int row;
	int col;

	reduce_edge_possibilities();
	row = 0;
	while (row < 4)
	{
		reduce_row_possibilities(row);
		row++;
	}
	col = 0;
	while (col < 4)
	{
		reduce_col_possibilities(col);
		col++;
	}
	return (is_grid_correct(g_grid));
}

int		possible(int row, int col, int value)
{
	int current_row;
	int current_col;

	current_col = 0;
	while (current_col < 4)
	{
		if (g_grid[row][current_col] == value)
			return (0);
		current_col++;
	}
	current_row = 0;
	while (current_row < 4)
	{
		if (g_grid[current_row][col] == value)
			return (0);
		current_row++;
	}
	return (1);
}

int g_tries = 0;

int		main_solve(void)
{
	int row;
	int col;
	int p;

	if (is_grid_correct(g_grid))
	{
		print_grid();
		return (1);
	}
	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			p = 0;
			if (g_grid[row][col] == 0)
			{
				while (p < 4)
				{
					if (!g_grid_possibilities[row][col][p])
					{
						p++;
						continue;
					}
					if (possible(row, col, g_grid_possibilities[row][col][p]))
					{
						g_grid[row][col] = g_grid_possibilities[row][col][p];
						if (main_solve())
							return (1);
						g_grid[row][col] = 0;
					}
					p++;
				}
				return (0);
			}
			else
			{
				g_tries++;
			}
			col++;
		}
		row++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int povs[16];

	if (argc != 2 || set_povs(povs, argv[1]) != 16)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	set_povs_by_row(povs, g_povs_by_row);
	set_povs_by_col(povs, g_povs_by_col);
	create_grid_possibilities();
	derive_from_povs();
	complete_grid();
	main_solve();
	printf("tries: %d\n", g_tries);
	return (1);
}
