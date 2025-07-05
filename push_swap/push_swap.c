/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:06:53 by seungule          #+#    #+#             */
/*   Updated: 2023/09/28 20:10:04 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_top_a_is_biggest(t_push_swap *ps, int stack_top_a);

int	main(int argc, char **argv)
{
	t_push_swap	ps;

	if (argc <= 1)
		return (1);
	ps.len = check_len(argv);
	ps.stack_a = (int *)malloc(sizeof(int) * (ps.len));
	if (!ps.stack_a)
		return (error(&ps));
	ps.stack_b = (int *)malloc(sizeof(int) * (ps.len));
	if (!ps.stack_b)
		return (error(&ps));
	ps.stack_count[1] = 0;
	ps.stack_count[0] = ps.len;
	parsing(&ps, argv);
	ps.stack_count[1] = 0;
	before_push_swap(&ps);
	free_stack(&ps);
}

int	push_swap(t_push_swap *ps)
{
	int	stack_top_a;
	int	stack_top_b;

	while (ps->stack_count[1] > 0)
	{
		where_biggest_num(ps);
		stack_top_a = ps->stack_a[ps->stack_count[0] - 1];
		stack_top_b = ps->stack_b[ps->stack_count[1] - 1];
		if (stack_top_a > stack_top_b)
			stack_top_a_is_biggest(ps, stack_top_a);
		else if (stack_top_b > stack_top_a)
			stack_top_b_is_biggest(ps, stack_top_b);
	}
	while (!is_sort_a(ps))
		rra(ps);
	return (0);
}

void	stack_top_a_is_biggest(t_push_swap *ps, int stack_top_a)
{
	while (ps->stack_a[0] > ps->stack_b[ps->stack_count[1] - 1])
	{
		if (stack_top_a < ps->stack_a[0])
			break ;
		rra(ps);
	}
	pa(ps);
}
