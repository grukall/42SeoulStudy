/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   before_push_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:07:46 by seungule          #+#    #+#             */
/*   Updated: 2023/09/28 18:54:34 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_first(t_push_swap *ps);
void	sort_second(t_push_swap *ps);
void	sort_third(t_push_swap *ps);

int	before_push_swap(t_push_swap *ps)
{
	if (is_sort_a(ps))
		return (0);
	if (ps->stack_count[0] <= 3)
	{
		sort_a(ps, ps->stack_a);
		return (0);
	}
	if (ps->stack_count[0] >= 500)
		greater_than_500(ps);
	else if (ps->stack_count[0] > 5)
		less_than_500(ps);
	else
		less_than_5(ps);
	sort_a(ps, ps->stack_a);
	push_swap(ps);
	return (0);
}

int	is_sort_a(t_push_swap *ps)
{
	int	i;

	i = 0;
	while (++i < ps->stack_count[0])
	{
		if (ps->stack_a[i] > ps-> stack_a[i - 1])
			return (0);
	}
	return (1);
}

void	sort_first(t_push_swap *ps)
{
	int	i;
	int	count;
	int	stack_top;

	i = 0;
	count = ps->stack_count[0];
	while (i++ < count)
	{
		stack_top = ps->stack_a[ps->stack_count[0] - 1];
		if (stack_top > ps->pivot[0])
			ra(ps);
		else
		{
			pb(ps);
			if (stack_top < ps->pivot[0] / 2 && ps->stack_count[1] > 1)
				rb(ps);
		}
		if (ps->stack_count[0] <= 3)
			break ;
	}
}

void	sort_second(t_push_swap *ps)
{
	int	i;
	int	count;
	int	stack_top;

	i = 0;
	count = ps->stack_count[0];
	while (i++ < count)
	{
		stack_top = ps->stack_a[ps->stack_count[0] - 1];
		if (stack_top > ps->pivot[1])
			ra(ps);
		else
		{
			pb(ps);
			if (stack_top < (ps->pivot[0] + ps->pivot[1]) / 2)
				rb(ps);
		}
	}
}

void	sort_third(t_push_swap *ps)
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
