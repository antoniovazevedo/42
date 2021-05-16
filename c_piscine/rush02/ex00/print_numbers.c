/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 21:20:06 by drodrigu          #+#    #+#             */
/*   Updated: 2020/12/13 21:20:09 by drodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdio.h>

void	print_separator(char *nbr, int i, int current_digit)
{
	int len;

	len = current_digit + i + 1;
	if (len >= 3 && i == 1 && nbr[0] != '0' && (nbr[1] != '0' || nbr[2] != '0'))
		ft_putstr(" ");
	else if (i == 0 && nbr[current_digit - 1] >= '2' &&
			nbr[current_digit] != '0')
		ft_putstr("-");
}

void	print_partial_10(char *nbr, t_dict_entry **dict)
{
	char c[3];

	c[0] = nbr[0];
	if (nbr[0] == '1')
		c[1] = nbr[1];
	else
		c[1] = '0';
	c[2] = '\0';
	print_exact_nbr(c, dict);
}

void	print_partial_100(char *nbr, t_dict_entry **dict)
{
	char c[3];

	c[0] = nbr[0];
	c[1] = '\0';
	print_exact_nbr(c, dict);
	ft_putstr(" ");
	print_exact_nbr("100", dict);
}

void	print_partial(char *nbr, int len, int i, t_dict_entry **dict)
{
	int		current_digit;

	current_digit = len - 1 - i;
	print_separator(nbr, i, current_digit);
	if (nbr[current_digit] != '0')
	{
		if (i == 2)
			print_partial_100(&nbr[current_digit], dict);
		else if (i == 1)
		{
			if (print_exact_nbr(&nbr[current_digit], dict))
				return ;
			print_partial_10(&nbr[current_digit], dict);
		}
		else if (i == 0 && nbr[current_digit - 1] != '1')
			print_exact_nbr(&nbr[current_digit], dict);
	}
	if (i >= 1)
		print_partial(nbr, len, i - 1, dict);
}

void	print_group(char *nbr, int digit_count, int index, t_dict_entry **dict)
{
	char	number[digit_count];
	char	*zeros;
	char	*dest;
	int		j;

	if (ft_strlen(nbr) == 1 && *nbr == '0')
	{
		print_exact_nbr(nbr, dict);
		return ;
	}
	ft_strlcpy(number, nbr, digit_count + 1);
	print_partial(number, digit_count, digit_count - 1, dict);
	if (index == 0)
		return ;
	zeros = "000";
	dest = (char *)malloc(sizeof(char) * 3 * index + 1);
	dest[0] = '1';
	j = 0;
	while (j < index)
	{
		ft_strcat(dest, zeros);
		j++;
	}
	ft_putstr(" ");
	print_exact_nbr(dest, dict);
}
