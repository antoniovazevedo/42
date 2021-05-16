/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazevedo <aazevedo@students.42lisbo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 22:28:47 by aazevedo          #+#    #+#             */
/*   Updated: 2020/12/07 22:30:25 by aazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

void	ft_putnbr_base(int nbr, char *base)
{
	int base_len;

	base_len = base_length(base);
	if (base_len < 2)
		return ;
	if (nbr == -2147483648)
	{
		ft_putnbr_base(nbr / base_len, base);
		write(1, &base[-nbr % base_len], 1);
		return ;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= base_len)
		ft_putnbr_base(nbr / base_len, base);
	write(1, &base[nbr % base_len], 1);
}
