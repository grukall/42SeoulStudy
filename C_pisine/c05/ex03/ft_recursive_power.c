/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 22:35:26 by seungule          #+#    #+#             */
/*   Updated: 2023/01/24 14:26:36 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	result;

	result = 1;
	if (power < 0)
		return (0);
	if (power > 1)
		result = ft_recursive_power(nb, power - 1);
	else if (power == 0)
		return (1);
	return (result * nb);
}
