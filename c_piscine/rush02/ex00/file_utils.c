/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazevedo <aazevedo@students.42lisbo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 19:42:04 by aazevedo          #+#    #+#             */
/*   Updated: 2020/12/12 21:15:40 by aazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		open_file(char *filename)
{
	int		file;

	file = open(filename, O_RDONLY);
	if (file < 0)
		return (0);
	return (file);
}

int		line_len(char *str)
{
	int i;
	int len;

	i = -1;
	len = 0;
	while (str[++i] != '\n')
		len++;
	return (len);
}

int		file_char_count(char *filename)
{
	int		file;
	int		count;
	char	c;

	file = open_file(filename);
	if (!file)
		return (0);
	count = 0;
	while (read(file, &c, 1))
		count++;
	close(file);
	return (count);
}

int		count_lines(char *str)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] != '\n')
			count++;
		i++;
	}
	return (count);
}

char	**get_lines(char *str, int line_count)
{
	char	**lines;
	int		i;
	int		j;
	int		l_nb;

	lines = (char **)malloc(sizeof(char *) * line_count);
	i = 0;
	l_nb = 0;
	while (str[i])
	{
		if (str[i] != '\n' && (i == 0 || str[i - 1] == '\n'))
		{
			lines[l_nb] = (char *)malloc(sizeof(char) * line_len(&str[i]) + 1);
			j = 0;
		}
		if (i > 0 && str[i] == '\n' && str[i + 1] != '\n')
			l_nb++;
		else
		{
			lines[l_nb][j] = str[i];
			j++;
		}
		i++;
	}
	return (lines);
}
