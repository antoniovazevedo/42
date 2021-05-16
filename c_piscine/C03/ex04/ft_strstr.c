/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazevedo <aazevedo@students.42lisbo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 14:06:25 by aazevedo          #+#    #+#             */
/*   Updated: 2020/12/13 21:27:45 by aazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int to_find_i;

	if (*to_find == 0)
		return (str);
	i = 0;
	while (str[i] != '\0')
	{
		to_find_i = 0;
		while (to_find[to_find_i] == str[i + to_find_i])
		{
			if (to_find[to_find_i + 1] == '\0')
			{
				return (str + i);
			}
			to_find_i++;
		}
		i++;
	}
	return (0);
}
