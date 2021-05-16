/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possibilities2.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpantoja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 12:08:37 by rpantoja          #+#    #+#             */
/*   Updated: 2020/12/07 12:08:40 by rpantoja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	reduce_row_possibilities(int row);
void	reduce_col_possibilities(int col);
void	pov_possibility_elimination(int row, int col, int pov);
void	reduce_edge_possibilities();
void	create_grid_possibilities();
