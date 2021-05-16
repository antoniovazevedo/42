/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazevedo <aazevedo@students.42lisbo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 01:01:55 by aazevedo          #+#    #+#             */
/*   Updated: 2020/12/17 01:04:50 by aazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strrev(char *str);
int		ft_strlen(char *str);
int		ft_atoi_base(char *str, char *base);
char	*int_to_base(int nbr, char *base, int radix);
int		is_valid_base(char *base);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

int		main(void)
{
	printf("%s\n", ft_convert_base("  42", "0123456789", "01"));
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb;
	int		radix;
	char	*result;

	if (!is_valid_base(base_from) || !is_valid_base(base_to))
		return (NULL);
	nb = ft_atoi_base(nbr, base_from);
	radix = ft_strlen(base_to);
	result = int_to_base(nb, base_to, radix);
	return (ft_strrev(result));
}

char	*int_to_base(int nbr, char *base, int radix)
{
	char		*result;
	int			i;
	int			is_negative;
	long int	number;

	result = malloc(sizeof(char) * 33);
	if (!result)
		return (0);
	i = 0;
	is_negative = 0;
	number = nbr;
	if (nbr < 0)
	{
		number = -number;
		is_negative = 1;
	}
	while (number > 0)
	{
		result[i] = base[number % radix];
		number = number / radix;
		i++;
	}
	if (is_negative)
		result[i] = '-';
	return (result);
}

int		has_repeated_chars(char *str)
{
	int		i;
	char	*chars;

	chars = str;
	while (*chars)
	{
		i = 1;
		while (*(chars + i))
		{
			if (*(chars + i) == *chars)
				return (1);
			i++;
		}
		chars++;
	}
	return (0);
}

int		is_valid_base(char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == ' ' || base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	if (has_repeated_chars(base) || i < 2)
		return (0);
	return (1);
}
