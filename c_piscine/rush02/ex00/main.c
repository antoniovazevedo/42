/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazevedo <aazevedo@students.42lisbo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 19:44:57 by aazevedo          #+#    #+#             */
/*   Updated: 2020/12/12 21:14:17 by aazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	char			*dict_name;
	char			*nbr;
	t_dict_entry	**dict;

	if (argc > 3 || argc < 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	dict_name = argc == 3 ? argv[1] : DEFAULT_DICT_NAME;
	nbr = argc == 3 ? argv[2] : argv[1];
	if (validate_nbr(nbr))
	{
		dict = get_dict(dict_name);
		nbr = parse_nbr(nbr);
		if (!dict || !can_dict_resolve_nbr(nbr, dict) ||
			!print_groups(nbr, ft_strlen(nbr), dict))
			dict_error();
	}
	return (0);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		print_exact_nbr(char *nbr, t_dict_entry **dict)
{
	t_dict_entry	*exact_entry;

	exact_entry = get_dict_entry(nbr, dict);
	if (exact_entry)
	{
		ft_putstr(exact_entry->word);
		return (1);
	}
	return (0);
}

int		print_groups(char *nbr, int len, t_dict_entry **dict)
{
	int group_count;
	int g;
	int g_digit_count;
	int first_g_digit_count;
	int printed_g_count;

	group_count = (len - 1) / 3 + 1;
	printed_g_count = 0;
	g = group_count - 1;
	first_g_digit_count = len % 3 == 0 ? 3 : len % 3;
	while (g >= 0)
	{
		g_digit_count = g == group_count - 1 ? first_g_digit_count : 3;
		if (g == group_count - 1 || ft_strncmp(nbr, "000", 3) != 0)
		{
			if (printed_g_count > 0)
				ft_putstr(" ");
			print_group(nbr, g_digit_count, g, dict);
		}
		nbr += g_digit_count;
		g--;
		printed_g_count++;
	}
	free_dict(dict);
	return (printed_g_count);
}
