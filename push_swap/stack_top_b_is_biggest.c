/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_top_b_is_biggest.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:46:58 by seungule          #+#    #+#             */
/*   Updated: 2023/09/28 20:05:57 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	top_up_round(t_push_swap *ps);
int		top_down_round(t_push_swap *ps, int stack_top_b);
void	top_down_round2(t_push_swap *ps);

void	stack_top_b_is_biggest(t_push_swap *ps, int stack_top_b)
{
	if (ps->stack_count[0] <= 2)
	{
		pa(ps);
		sort_a(ps, ps->stack_a);
	}
	else
	{
		if (where_next_num(ps, stack_top_b))
			top_up_round(ps);
		else
			top_down_round(ps, stack_top_b);
	}
}

void	top_up_round(t_push_swap *ps)
{
	int	i;
	int	count;

	i = 0;
	count = ps->stack_count[0] - 1;
	while (i < count && ps->stack_a[count] != ps->biggest)
	{
		ra(ps);
		i++;
	}
	pa(ps);
	count = ps->stack_count[0] - 1;
	if (ps->stack_a[count] > ps->stack_a[count - 1])
		sa(ps);
}

int	top_down_round(t_push_swap *ps, int stack_top_b)
{
	int	i;
	int	count;

	i = 1;
	count = ps->stack_count[0] - 1;
	if (ps->biggest < stack_top_b)
	{
		top_down_round2(ps);
		return (0);
	}
	while (i < count + 1 && ps->stack_a[count] != ps->biggest)
	{
		rra(ps);
		i++;
	}
	pa(ps);
	count = ps->stack_count[0] - 1;
	if (ps->stack_a[count] > ps->stack_a[count - 1])
		sa(ps);
	return (0);
}

void	top_down_round2(t_push_swap *ps)
{
	int	i;
	int	count;

	i = 1;
	count = ps->stack_count[0] - 1;
	while (i < count + 1 && ps->stack_a[0] != ps->biggest)
	{
		rra(ps);
		i++;
	}
	pa(ps);
	ra(ps);
}
