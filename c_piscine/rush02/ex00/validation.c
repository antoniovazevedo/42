/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazevedo <aazevedo@students.42lisbo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 00:04:09 by aazevedo          #+#    #+#             */
/*   Updated: 2020/12/14 11:54:00 by aazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	dict_error(void)
{
	write(1, "Dict Error\n", 11);
}

char	*parse_nbr(char *nbr)
{
	int i;

	i = 0;
	while (nbr[i] == '0' && nbr[i + 1] != '\0')
	{
		i++;
	}
	return (&nbr[i]);
}

int		validate_nbr(char *nbr)
{
	int i;

	i = 0;
	while (nbr[i])
	{
		if (nbr[i] < '0' || nbr[i] > '9')
		{
			write(1, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}

int		can_dict_resolve_nbr(char *nbr, t_dict_entry **dict)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(nbr);
	while (1)
	{
		if (len <= ft_strlen(dict[i]->nbr) + 2)
			return (1);
		if (i + 1 == dict[i]->dict_size)
			break ;
		i++;
	}
	return (0);
}
