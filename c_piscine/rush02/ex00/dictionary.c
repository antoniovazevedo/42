/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 21:23:50 by drodrigu          #+#    #+#             */
/*   Updated: 2020/12/14 12:14:45 by aazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_dict_entry	**get_dict(char *filename)
{
	int		file;
	int		file_size;
	int		line_count;
	char	*text;
	char	**lines;

	file = open_file(filename);
	if (!file)
		return (NULL);
	file_size = file_char_count(filename);
	text = (char *)malloc(file_size * sizeof(char));
	read(file, text, file_size);
	close(file);
	line_count = count_lines(text);
	lines = get_lines(text, line_count);
	free(text);
	return (dict_from_lines(lines, line_count));
}

t_dict_entry	*get_dict_entry(char *nbr, t_dict_entry **dict)
{
	int i;

	i = 0;
	while (1)
	{
		if (ft_strcmp(nbr, dict[i]->nbr) == 0)
			return (dict[i]);
		if (i + 1 == dict[i]->dict_size)
			break ;
		i++;
	}
	return (NULL);
}

void			free_dict_entry(t_dict_entry *entry)
{
	free(entry->nbr);
	free(entry->word);
	free(entry);
}

void			free_dict(t_dict_entry **dict)
{
	int i;

	i = 0;
	while (1)
	{
		free_dict_entry(dict[i]);
		if (i + 1 == dict[i]->dict_size)
			break ;
		i++;
	}
	free(dict);
}
