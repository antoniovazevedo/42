/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazevedo <aazevedo@students.42lisbo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 19:19:36 by aazevedo          #+#    #+#             */
/*   Updated: 2020/11/26 19:32:35 by aazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	char symbol;

	symbol = 'P';
	if (n < 0)
	{
		symbol = 'N';
	}
	write(1, &symbol, 1);
}
