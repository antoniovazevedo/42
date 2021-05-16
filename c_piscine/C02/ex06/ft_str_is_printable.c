/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazevedo <aazevedo@students.42lisbo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 19:05:12 by aazevedo          #+#    #+#             */
/*   Updated: 2020/12/01 19:55:18 by aazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	only_printable;

	only_printable = 1;
	while (*str != '\0')
	{
		if (*str < 32 || *str > 126)
		{
			only_printable = 0;
			break ;
		}
		str++;
	}
	return (only_printable);
}
