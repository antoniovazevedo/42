/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazevedo <aazevedo@students.42lisbo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 20:12:27 by aazevedo          #+#    #+#             */
/*   Updated: 2020/12/17 11:49:22 by aazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int					ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char				*ft_strdup(char *src)
{
	char	*ptr;
	int		i;
	int		len;

	len = 0;
	while (src[len])
		len++;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (0);
	i = 0;
	while (src[i])
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str *list;

	list = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!list)
		return (list);
	i = 0;
	while (i < ac)
	{
		list[i].size = ft_strlen(av[i]);
		list[i].str = av[i];
		list[i].copy = ft_strdup(av[i]);
		i++;
	}
	list[i].str = 0;
	return (list);
}
