/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazevedo <aazevedo@students.42lisbo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 23:31:41 by aazevedo          #+#    #+#             */
/*   Updated: 2020/12/14 00:37:25 by aazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		has_repeated_chars(char *str, int length)
{
	int		i;
	int		j;
	char	chars[length];
	int		has_repeated_chars;

	i = 0;
	has_repeated_chars = 0;
	while (i < length)
	{
		j = 0;
		while (i > 0 && j < length && chars[j] != 0)
		{
			if (chars[j] == str[i])
			{
				has_repeated_chars = 1;
				break ;
			}
			j++;
		}
		chars[i] = str[i];
		i++;
	}
	return (has_repeated_chars);
}

int		base_length(char *base)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (base[i] != 0)
	{
		if (base[i] == ' ' || base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	if (has_repeated_chars(base, i + 1))
		return (0);
	return (i);
}

int		base_to_int(char *base, char c)
{
	int i;

	i = 0;
	while (base[i] != 0)
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_atoi_base(char *str, char *base)
{
	int minus;
	int number;
	int radix;

	minus = 1;
	number = 0;
	radix = base_length(base);
	if (!radix)
		return (0);
	while (*str != 0)
	{
		if (base_to_int(base, *str) >= 0)
		{
			number *= radix;
			number += base_to_int(base, *str);
		}
		else if (number > 0)
			break ;
		else if (*str == '-')
			minus *= -1;
		str++;
	}
	return (number * minus);
}
