/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazevedo <aazevedo@students.42lisbo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 18:26:35 by aazevedo          #+#    #+#             */
/*   Updated: 2020/12/01 18:27:10 by aazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	only_uppercase;

	only_uppercase = 1;
	while (*str != '\0')
	{
		if (*str < 65 || *str > 90)
		{
			only_uppercase = 0;
			break ;
		}
		str++;
	}
	return (only_uppercase);
}
