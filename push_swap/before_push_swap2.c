/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   before_push_swap2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:12:39 by seungule          #+#    #+#             */
/*   Updated: 2023/09/28 20:18:36 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	less_than_5(t_push_swap *ps)
{
	while (ps->stack_count[0] > 3)
		pb(ps);
}

void	less_than_500(t_push_swap *ps)
{
	average_num(ps);
	sort_first(ps);
	sort_second(ps);
	sort_third(ps);
}

void	greater_than_500(t_push_swap *ps)
{
	average_num2(ps);
	sort_first(ps);
	sort_second(ps);
	sort_third2(ps);
	sort_forth(ps);
}
