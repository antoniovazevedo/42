/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazevedo <aazevedo@students.42lisbo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 13:10:51 by aazevedo          #+#    #+#             */
/*   Updated: 2020/12/04 13:11:45 by aazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
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
