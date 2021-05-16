/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazevedo <aazevedo@students.42lisbo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 21:53:24 by aazevedo          #+#    #+#             */
/*   Updated: 2020/12/09 21:55:14 by aazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int result;

	if (nb == 0)
		return (1);
	else if (nb < 0)
		return (0);
	result = nb;
	while (nb > 1)
		result *= --nb;
	return (result);
}
