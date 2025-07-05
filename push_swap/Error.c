/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:34:26 by seungule          #+#    #+#             */
/*   Updated: 2023/09/24 10:11:23 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_argv(char **argv);

void	free_stack(t_push_swap *ps)
{
	if (ps)
	{
		if (ps->stack_a)
			free(ps->stack_a);
		if (ps->stack_b)
			free(ps->stack_b);
	}
}

int	error(t_push_swap *ps)
{
	if (ps)
		free_stack(ps);
	ft_printf("Error\n");
	exit(1);
}
