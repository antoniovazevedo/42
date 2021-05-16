/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary_entries.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazevedo <aazevedo@students.42lisbo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 00:03:59 by aazevedo          #+#    #+#             */
/*   Updated: 2020/12/13 00:04:00 by aazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char			*dict_entry_nbr(char **str)
{
	char		*nbr;
	int			i;

	nbr = (char *)malloc(sizeof(char) * 38);
	i = 0;
	while (**str >= '0' && **str <= '9')
	{
		nbr[i] = **str;
		i++;
		(*str)++;
	}
	while (**str == ' ')
		(*str)++;
	if (**str != ':')
		return (NULL);
	(*str)++;
	return (nbr);
}

char			*dict_entry_word(char *str)
{
	char		*word;
	int			i;

	word = (char *)malloc(sizeof(char) * 20);
	i = 0;
	while (*str > ' ' && *str < 127)
	{
		word[i] = *str;
		i++;
		str++;
	}
	return (word);
}

t_dict_entry	*dict_entry_from_line(char *str)
{
	t_dict_entry	*entry;
	char			*nbr;
	char			*word;

	entry = (t_dict_entry *)malloc(sizeof(t_dict_entry));
	nbr = dict_entry_nbr(&str);
	if (nbr == NULL)
		return (NULL);
	while (*str == ' ')
		str++;
	word = dict_entry_word(str);
	if (word == NULL)
		return (NULL);
	entry->nbr = nbr;
	entry->word = word;
	return (entry);
}

t_dict_entry	**dict_from_lines(char **lines, int line_count)
{
	t_dict_entry	**dict;
	t_dict_entry	*entry;
	int				i;

	dict = (t_dict_entry **)malloc(sizeof(t_dict_entry *) * line_count);
	i = 0;
	while (i < line_count)
	{
		entry = dict_entry_from_line(&lines[i][0]);
		if (!entry)
			return (NULL);
		entry->dict_size = line_count;
		dict[i] = entry;
		i++;
	}
	free(lines);
	return (dict);
}
