/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazevedo <aazevedo@students.42lisbo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:55:31 by aazevedo          #+#    #+#             */
/*   Updated: 2020/12/14 17:56:40 by aazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int i;

	if (nb <= 1)
		return (0);
	else if (nb > 2 && nb % 2 == 0)
		return (0);
	else if (nb == 2147483647)
		return (1);
	i = 3;
	while (i < nb / 2)
	{
		if (nb % i == 0)
			return (0);
		else if (i * i > nb)
			return (1);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int i;

	i = nb;
	while (!ft_is_prime(i))
		i++;
	return (i);
}
