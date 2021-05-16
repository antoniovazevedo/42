/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possibilities.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpantoja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 11:46:53 by rpantoja          #+#    #+#             */
/*   Updated: 2020/12/07 12:06:34 by rpantoja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	reduce_cell_possibilities(int row, int col, int by_row);
void	row_possibility_count(int row, int possibilities[5]);
void	col_possibility_count(int col, int possibilities[5]);
int		calculate_unique_possibility(int possibilities[5]);
void	fill_row_unique_possibility(int row);
void	fill_col_unique_possibility(int col);
