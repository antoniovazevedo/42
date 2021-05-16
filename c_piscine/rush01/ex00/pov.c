/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpantoja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 12:14:51 by rpantoja          #+#    #+#             */
/*   Updated: 2020/12/07 12:15:14 by rpantoja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "variables.h"

int		set_povs(int *povs, char *str)
{
	int		i;
	char	prev_c;

	i = 0;
	while (*str != 0)
	{
		if (*str == 32)
		{
			if (prev_c == 32 || i == 0)
				return (0);
			prev_c = *str;
			str++;
			continue;
		}
		prev_c = *str;
		if (*str < '1' || *str > '4')
			return (0);
		povs[i] = *str - '0';
		i++;
		str++;
	}
	if (prev_c == 32)
		return (0);
	return (i);
}

void	set_povs_by_row(int *povs, int povs_by_row[4][2])
{
	int i;
	int j;
	int row;

	i = 8;
	j = 0;
	row = 0;
	while (i < 16)
	{
		if (row > 3)
		{
			row = 0;
			j++;
		}
		povs_by_row[row][j] = povs[i];
		i++;
		row++;
	}
}

void	set_povs_by_col(int *povs, int povs_by_col[4][2])
{
	int i;
	int j;
	int col;

	i = 0;
	j = 0;
	col = 0;
	while (i < 8)
	{
		if (col > 3)
		{
			col = 0;
			j++;
		}
		povs_by_col[col][j] = povs[i];
		i++;
		col++;
	}
}

int		get_row_pov(int row, int col)
{
	int index;

	if (col != 0 && col != 3)
		return (0);
	index = col == 0 ? 0 : 1;
	return (g_povs_by_row[row][index]);
}

int		get_col_pov(int row, int col)
{
	int index;

	if (row != 0 && row != 3)
		return (0);
	index = row == 0 ? 0 : 1;
	return (g_povs_by_col[col][index]);
}
