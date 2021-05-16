/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazevedo <aazevedo@students.42lisbo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:42:08 by aazevedo          #+#    #+#             */
/*   Updated: 2020/12/01 13:42:35 by aazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	only_digits;

	only_digits = 1;
	while (*str != '\0')
	{
		if (*str < 48 || *str > 57)
		{
			only_digits = 0;
			break ;
		}
		str++;
	}
	return (only_digits);
}
