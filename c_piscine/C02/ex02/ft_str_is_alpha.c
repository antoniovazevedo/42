/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazevedo <aazevedo@students.42lisbo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 14:27:15 by aazevedo          #+#    #+#             */
/*   Updated: 2020/12/02 20:04:50 by aazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int only_alpha;

	only_alpha = 1;
	while (*str != '\0')
	{
		if (*str < 65 || (*str >= 91 && *str <= 96) || *str > 122)
		{
			only_alpha = 0;
		}
		str++;
	}
	return (only_alpha);
}
