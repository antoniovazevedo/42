/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazevedo <aazevedo@students.42lisbo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:48:12 by aazevedo          #+#    #+#             */
/*   Updated: 2020/12/01 13:48:42 by aazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	only_lowercase;

	only_lowercase = 1;
	while (*str != '\0')
	{
		if (*str < 97 || *str > 122)
		{
			only_lowercase = 0;
			break ;
		}
		str++;
	}
	return (only_lowercase);
}
