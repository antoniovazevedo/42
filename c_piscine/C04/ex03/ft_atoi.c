/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazevedo <aazevedo@students.42lisbo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 23:31:41 by aazevedo          #+#    #+#             */
/*   Updated: 2020/12/06 00:16:01 by aazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int minus;
	int number;

	minus = 1;
	number = 0;
	while (*str != 0)
	{
		if (*str >= '0' && *str <= '9')
		{
			number *= 10;
			number += *str - '0';
			str++;
			continue;
		}
		else if (number > 0)
			break ;
		else if (*str == '-')
			minus *= -1;
		str++;
	}
	return (number * minus);
}
