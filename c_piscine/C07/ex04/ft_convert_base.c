/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazevedo <aazevedo@students.42lisbo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 00:57:42 by aazevedo          #+#    #+#             */
/*   Updated: 2020/12/17 00:59:09 by aazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strrev(char *str)
{
	char	*rev_str;
	int		len;
	int		i;

	len = ft_strlen(str);
	rev_str = (char *)malloc(sizeof(char) * len + 1);
	i = len;
	while (i >= 0)
	{
		rev_str[len - i - 1] = str[i];
		i--;
	}
	rev_str[len - i - 1] = 0;
	return (rev_str);
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
	radix = ft_strlen(base);
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
