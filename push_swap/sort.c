/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:21:31 by seungule          #+#    #+#             */
/*   Updated: 2023/09/28 20:13:47 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_biggest_num_top(t_push_swap *ps);
void	find_biggest_num_bottom(t_push_swap *ps);

void	sort_a(t_push_swap *ps, int *stack)
{
	if (ps->stack_count[0] == 2)
	{
		if (stack[1] > stack[0])
			sa(ps);
	}
	else if (ps->stack_count[0] == 3)
	{
		if (stack[1] > stack[0] && stack[0] > stack[2])
		{
			rra(ps);
			sa(ps);
		}
		else if (stack[0] > stack[2] && stack[2] > stack[1])
			sa(ps);
		else if (stack[1] > stack[2] && stack[2] > stack[0])
			rra(ps);
		else if (stack[2] > stack[0] && stack[0] > stack[1])
			ra(ps);
		else if (stack[2] > stack[1] && stack[1] > stack[0])
		{
			ra(ps);
			sa(ps);
		}
	}
}

int	where_next_num(t_push_swap *ps, int biggest)
{
	int	i;

	i = 0;
	ps->biggest = ps->stack_a[ps->stack_count[0] - 1];
	while (i < ps->stack_count[0])
	{
		if (biggest < ps->stack_a[ps->stack_count[0] - 1 - i])
		{
			ps->biggest = ps->stack_a[ps->stack_count[0] - 1 - i];
			ps->biggest_index = ps->stack_count[0] - 1 - i;
			break ;
		}
		else if (ps->biggest < ps->stack_a[ps->stack_count[0] - 1 - i])
		{
			ps->biggest = ps->stack_a[ps->stack_count[0] - 1 - i];
			ps->biggest_index = ps->stack_count[0] - 1 - i;
		}
		i++;
	}
	if (ps->biggest_index >= ps->stack_count[0] / 2)
		return (1);
	return (0);
}

int	where_biggest_num(t_push_swap *ps)
{
	int	i;
	int	j;

	find_biggest_num_top(ps);
	find_biggest_num_bottom(ps);
	j = 0;
	if (ps->biggest_index >= ps->stack_count[1] / 2)
	{
		i = (ps->stack_count[1] - 1) - ps->biggest_index;
		while (j++ < i)
			rb(ps);
	}
	else
	{
		while (j++ < ps->biggest_index + 1)
			rrb(ps);
	}
	return (0);
}

void	find_biggest_num_top(t_push_swap *ps)
{
	int	i;
	int	temp;

	i = 2;
	ps->biggest = ps->stack_b[ps->stack_count[1] - 1];
	ps->biggest_index = ps->stack_count[1] - 1;
	temp = ps->biggest;
	while (i <= 3)
	{
		temp = ps->stack_b[ps->stack_count[1] - i];
		if (temp > ps->biggest)
		{
			ps->biggest = temp;
			ps->biggest_index = ps->stack_count[1] - i;
		}
		i++;
	}
}

void	find_biggest_num_bottom(t_push_swap *ps)
{
	int	i;
	int	temp;

	i = 1;
	temp = ps->stack_b[0];
	while (i <= 3)
	{
		temp = ps->stack_b[0 + i];
		if (temp > ps->biggest)
		{
			ps->biggest = temp;
			ps->biggest_index = i;
		}
		i++;
	}
}
