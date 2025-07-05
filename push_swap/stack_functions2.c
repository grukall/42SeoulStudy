/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:01:33 by seungule          #+#    #+#             */
/*   Updated: 2023/09/09 13:04:30 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_push_swap *ps)
{
	int	temp;
	int	count;

	count = ps->stack_count[0];
	temp = ps->stack_a[count - 1];
	while (count > 1)
	{
		ps->stack_a[count - 1] = ps->stack_a[count - 2];
		count--;
	}
	ps->stack_a[0] = temp;
	ft_printf("ra\n");
	return (1);
}

int	rb(t_push_swap *ps)
{
	int	temp;
	int	count;

	count = ps->stack_count[1];
	temp = ps->stack_b[count - 1];
	while (count > 1)
	{
		ps->stack_b[count - 1] = ps->stack_b[count - 2];
		count--;
	}
	ps->stack_b[0] = temp;
	ft_printf("rb\n");
	return (1);
}

int	rr(t_push_swap *ps)
{
	if (!ra(ps) || !rb(ps))
		return (0);
	ft_printf("rr\n");
	return (1);
}

int	rra(t_push_swap *ps)
{
	int	temp;
	int	count;
	int	i;

	i = 1;
	count = ps->stack_count[0];
	temp = ps->stack_a[0];
	while (i < count)
	{
		ps->stack_a[i - 1] = ps->stack_a[i];
		i++;
	}
	ps->stack_a[count - 1] = temp;
	ft_printf("rra\n");
	return (1);
}

int	rrb(t_push_swap *ps)
{
	int	temp;
	int	count;
	int	i;

	i = 0;
	count = ps->stack_count[1];
	temp = ps->stack_b[0];
	while (i < count)
	{
		ps->stack_b[i - 1] = ps->stack_b[i];
		i++;
	}
	ps->stack_b[count - 1] = temp;
	ft_printf("rrb\n");
	return (1);
}
