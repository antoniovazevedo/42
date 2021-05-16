/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazevedo <aazevedo@students.42lisbo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 19:42:26 by aazevedo          #+#    #+#             */
/*   Updated: 2020/12/03 19:47:11 by aazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_strlowcase(char c)
{
	if (c >= 97)
		return (c);
	else if (c >= 48 && c <= 57)
		return (c);
	return (c + 32);
}

char	ft_strupcase(char c)
{
	if (c <= 90)
		return (c);
	else if (c >= 48 && c <= 57)
		return (c);
	return (c - 32);
}

int		is_alphanumeric(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else if (c >= 65 && c <= 90)
		return (1);
	else if (c >= 97 && c <= 122)
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!is_alphanumeric(str[i]))
		{
			i++;
			continue;
		}
		if (i == 0 || !is_alphanumeric(str[i - 1]))
		{
			str[i] = ft_strupcase(str[i]);
		}
		else
		{
			str[i] = ft_strlowcase(str[i]);
		}
		i++;
	}
	return (str);
}
