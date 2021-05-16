/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazevedo <aazevedo@students.42lisbo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 22:54:39 by aazevedo          #+#    #+#             */
/*   Updated: 2020/12/15 22:54:53 by aazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int length;

	length = 0;
	while (*str != '\0')
	{
		length++;
		str++;
	}
	return (length);
}

int		strs_total_len(char **strs, int size)
{
	int i;
	int length;

	i = 0;
	length = 0;
	while (i < size)
	{
		length += ft_strlen(strs[i]);
		i++;
	}
	return (length);
}

char	*concat(char *str, int size, char **strs, char *sep)
{
	int i;
	int str_i;
	int j;
	int k;

	i = 0;
	str_i = 0;
	while (str_i < size)
	{
		j = 0;
		k = 0;
		while (strs[str_i][j] != '\0')
			str[i++] = strs[str_i][j++];
		if (str_i == size - 1)
			str[i] = 0;
		else if (str_i < size - 1)
			while (sep[k] != '\0')
				str[i++] = sep[k++];
		str_i++;
	}
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		str_size;

	if (!size)
	{
		str = malloc(1);
		*str = '\0';
		return (str);
	}
	str_size = strs_total_len(strs, size) + (size - 1) * ft_strlen(sep);
	str = (char *)malloc(sizeof(char) * str_size);
	if (!str)
		return (NULL);
	str = concat(str, size, strs, sep);
	return (str);
}
