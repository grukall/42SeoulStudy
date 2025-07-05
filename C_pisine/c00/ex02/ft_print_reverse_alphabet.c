/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex02.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:57:48 by seungule          #+#    #+#             */
/*   Updated: 2023/01/14 16:34:43 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void);

void	ft_print_reverse_alphabet(void)
{
	char	a;

	a = 122;
	while (a > 96)
	{
		write (1, &a, 1);
		a--;
	}
}
