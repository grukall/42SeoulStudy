/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 19:35:58 by seunlee2          #+#    #+#             */
/*   Updated: 2023/01/31 19:38:32 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_min(int a, int b)
{
	int	temp;

	temp = 0;
	if (a < b)
		temp = a;
	else
		temp = b;
	return (temp);
}

int	ft_max(int a, int b)
{
	int	temp;

	temp = 0;
	if (a > b)
		temp = a;
	else
		temp = b;
	return (temp);
}
