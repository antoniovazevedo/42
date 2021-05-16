/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazevedo <aazevedo@students.42lisbo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 12:44:59 by aazevedo          #+#    #+#             */
/*   Updated: 2020/12/10 13:02:16 by aazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned char current_char;

	while (*str != '\0')
	{
		current_char = *str;
		if (current_char < 32 || current_char >= 127)
		{
			ft_putchar('\\');
			ft_putchar("0123456789abcdef"[current_char / 16]);
			ft_putchar("0123456789abcdef"[current_char % 16]);
		}
		else
			ft_putchar(current_char);
		str++;
	}
}
