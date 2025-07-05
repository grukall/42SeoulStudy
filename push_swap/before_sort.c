/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   before_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:10:31 by seungule          #+#    #+#             */
/*   Updated: 2023/09/28 18:38:09 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_third2(t_push_swap *ps)
{
	int	i;
	int	count;
	int	stack_top;

	i = 0;
	count = ps->stack_count[0];
	while (i++ < count)
	{
		stack_top = ps->stack_a[ps->stack_count[0] - 1];
		if (stack_top > ps->pivot[2])
			ra(ps);
		else
		{
			pb(ps);
			if (stack_top < (ps->pivot[1] + ps->pivot[2]) / 2)
				rb(ps);
		}
	}
}

void	sort_forth(t_push_swap *ps)
{
	int	i;
	int	count;
	int	stack_top;

	i = 0;
	count = ps->stack_count[0];
	while (i++ < count - 3 && ps->stack_count[0] > 1)
	{
		stack_top = ps->stack_a[ps->stack_count[0] - 1];
		pb(ps);
		if (stack_top < ps->num)
			rb(ps);
		if (ps->stack_count[0] <= 3)
			break ;
	}
}
