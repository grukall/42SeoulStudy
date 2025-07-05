/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:14:28 by seungule          #+#    #+#             */
/*   Updated: 2023/01/24 14:17:58 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int	a;

	a = 1;
	if (nb < 0)
		return (0);
	if (nb > 0)
		a = ft_recursive_factorial(nb - 1);
	if (nb == 0)
		return (1);
	return (a * nb);
}
