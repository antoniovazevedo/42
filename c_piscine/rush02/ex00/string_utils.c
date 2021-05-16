/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 21:22:38 by drodrigu          #+#    #+#             */
/*   Updated: 2020/12/13 21:22:40 by drodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char			*ft_strcat(char *dest, char *src)
{
	int i;
	int dest_i;

	i = 0;
	dest_i = 0;
	while (dest[dest_i] != '\0')
	{
		dest_i++;
	}
	while (src[i] != '\0')
	{
		dest[dest_i] = src[i];
		i++;
		dest_i++;
	}
	dest[dest_i] = '\0';
	return (dest);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int src_len;

	i = 0;
	src_len = 0;
	while (src[src_len])
		src_len++;
	if (!size)
		return (src_len);
	while (size > 0 && i < size - 1 && *src != '\0')
	{
		dest[i] = *src;
		i++;
		src++;
	}
	dest[i] = '\0';
	return (src_len);
}

int				ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int				ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (i < n && (*s1 != '\0' || *s2 != '\0'))
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		if (*s1 != '\0')
			s1++;
		if (*s2 != '\0')
			s2++;
		i++;
	}
	return (0);
}

int				ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' || *s2 != '\0')
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		if (*s1 != '\0')
			s1++;
		if (*s2 != '\0')
			s2++;
	}
	return (0);
}
