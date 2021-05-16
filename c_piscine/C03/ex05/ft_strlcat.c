/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazevedo <aazevedo@students.42lisbo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 14:41:38 by aazevedo          #+#    #+#             */
/*   Updated: 2020/12/08 13:57:52 by aazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len] != 0)
		len++;
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dest_i;
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	max;

	i = 0;
	dest_len = ft_strlen(dest);
	dest_i = dest_len;
	src_len = ft_strlen(src);
	max = size - dest_len - 1;
	while (i < max && max > 0 && src[i] != '\0')
	{
		dest[dest_i] = src[i];
		i++;
		dest_i++;
	}
	dest[dest_i] = '\0';
	return (size < dest_len) ? size + src_len : dest_len + src_len;
}
