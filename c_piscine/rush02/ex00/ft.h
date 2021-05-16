/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazevedo <aazevedo@students.42lisbo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 22:36:52 by aazevedo          #+#    #+#             */
/*   Updated: 2020/12/12 22:36:56 by aazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define DEFAULT_DICT_NAME "numbers.dict"

typedef struct	s_dict_entry
{
	char	*nbr;
	char	*word;
	int		dict_size;
}				t_dict_entry;

void			ft_putstr(char *str);
int				print_exact_nbr(char *nbr, t_dict_entry **dict);
int				print_groups(char *nbr, int len, t_dict_entry **dict);

int				open_file(char *filename);
int				line_len(char *str);
int				file_char_count(char *filename);
int				count_lines(char *str);
char			**get_lines(char *str, int line_count);

t_dict_entry	**get_dict(char *filename);
t_dict_entry	*get_dict_entry(char *nbr, t_dict_entry **dict);
void			free_dict_entry(t_dict_entry *entry);
void			free_dict(t_dict_entry **dict);

char			*dict_entry_nbr(char **str);
char			*dict_entry_word(char *str);
t_dict_entry	*dict_entry_from_line(char *str);
t_dict_entry	**dict_from_lines(char **lines, int line_count);

void			dict_error(void);
char			*parse_nbr(char *nbr);
int				validate_nbr(char *nbr);
int				can_dict_resolve_nbr(char *nbr, t_dict_entry **dict);

char			*ft_strcat(char *dest, char *src);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
int				ft_strlen(char *str);
int				ft_strncmp(char *s1, char *s2, unsigned int n);
int				ft_strcmp(char *s1, char *s2);

void			print_separator(char *nbr, int i, int current_digit);
void			print_partial_10(char *nbr, t_dict_entry **dict);
void			print_partial_100(char *nbr, t_dict_entry **dict);
void			print_partial(char *nbr, int len, int i, t_dict_entry **dict);
void			print_group(char *nbr, int len, int index, t_dict_entry **dict);

#endif
