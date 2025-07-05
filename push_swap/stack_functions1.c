/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:01:18 by seungule          #+#    #+#             */
/*   Updated: 2023/09/09 13:04:23 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_push_swap *ps)
{
	int	temp;
	int	len;

	len = ps->stack_count[0];
	if (!ps->stack_a || ps->stack_count[0] <= 1)
		return (0);
	temp = ps->stack_a[len - 1];
	ps->stack_a[len - 1] = ps->stack_a[len - 2];
	ps->stack_a[len - 2] = temp;
	ft_printf("sa\n");
	return (1);
}

int	sb(t_push_swap *ps)
{
	int	temp;
	int	len;

	len = ps->stack_count[1];
	if (!ps->stack_b || ps->stack_count[1] <= 1)
		return (0);
	temp = ps->stack_b[len - 1];
	ps->stack_b[len - 1] = ps->stack_b[len - 2];
	ps->stack_b[len - 2] = temp;
	ft_printf("sb\n");
	return (1);
}

int	ss(t_push_swap *ps)
{
	if (!sa(ps) || !sb(ps))
		return (0);
	ft_printf("ss\n");
	return (1);
}

int	pa(t_push_swap *ps)
{
	if (ps->stack_count[1] == 0)
		return (0);
	ps->stack_a[ps->stack_count[0]] = ps->stack_b[ps->stack_count[1] - 1];
	ps->stack_count[0]++;
	ps->stack_count[1]--;
	ft_printf("pa\n");
	return (1);
}

int	pb(t_push_swap *ps)
{
	if (ps->stack_count[0] == 0)
		return (0);
	ps->stack_b[ps->stack_count[1]] = ps->stack_a[ps->stack_count[0] - 1];
	ps->stack_count[0]--;
	ps->stack_count[1]++;
	ft_printf("pb\n");
	return (1);
}
