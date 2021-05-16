/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazevedo <aazevedo@students.42lisbo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 11:22:53 by aazevedo          #+#    #+#             */
/*   Updated: 2020/12/01 11:23:54 by aazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int div;
	int div_mod;

	div = *a / *b;
	div_mod = *a % *b;
	*a = div;
	*b = div_mod;
}
