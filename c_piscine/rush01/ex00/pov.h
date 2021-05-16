/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pov.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpantoja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 12:15:18 by rpantoja          #+#    #+#             */
/*   Updated: 2020/12/07 12:16:59 by rpantoja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		set_povs(int *povs, char *str);
void	set_povs_by_row(int *povs, int povs_by_row[4][2]);
void	set_povs_by_col(int *povs, int povs_by_col[4][2]);
int		get_row_pov(int row, int col);
int		get_col_pov(int row, int col);
