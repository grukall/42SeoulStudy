/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:09:57 by seungule          #+#    #+#             */
/*   Updated: 2023/09/28 20:17:17 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_int_range(int res, char argv_input, int flag, t_push_swap *ps);

void	average_num(t_push_swap *ps)
{
	int	i;
	int	*arr;

	i = -1;
	arr = (int *)malloc(sizeof(int) * ps->stack_count[0]);
	while (++i < ps->stack_count[0])
		arr[i] = ps->stack_a[i];
	quicksort(arr, 0, ps->stack_count[0] - 1);
	ps->pivot[0] = arr[ps->stack_count[0] / 3];
	ps->pivot[1] = arr[ps->stack_count[0] / 3 * 2];
	ps->num = arr[ps->stack_count[0] / 6 * 5];
	free(arr);
}

void	average_num2(t_push_swap *ps)
{
	int	i;
	int	*arr;

	i = -1;
	arr = (int *)malloc(sizeof(int) * ps->stack_count[0]);
	while (++i < ps->stack_count[0])
		arr[i] = ps->stack_a[i];
	quicksort(arr, 0, ps->stack_count[0] - 1);
	ps->pivot[0] = arr[ps->stack_count[0] / 4];
	ps->pivot[1] = arr[ps->stack_count[0] / 4 * 2];
	ps->pivot[2] = arr[ps->stack_count[0] / 4 * 3];
	ps->num = arr[ps->stack_count[0] / 8 * 7];
	free(arr);
}

int	push_stack(t_push_swap *ps, char **result, int index)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (result[i])
	{
		j = ps->len;
		if (!check_argv(result[i], ps))
			error(ps);
		temp = ft_atoi(result[i]);
		ps->stack_a[ps->len - index - 1] = temp;
		while (--j > ps->len - index - 1)
		{
			if (ps->stack_a[j] == ps->stack_a[ps->len - index - 1])
				error(ps);
		}
		index++;
		i++;
	}
	return (index);
}

int	check_argv(char *argv_input, t_push_swap *ps)
{
	int	res;
	int	flag;

	res = 0;
	flag = 1;
	if (argv_input[0] == '0' && argv_input[1] != '\0')
		error(ps);
	while (*argv_input)
	{
		if (*argv_input == '+' || *argv_input == '-')
		{
			if (*argv_input == '-')
				flag = -1;
			if (*(++argv_input) == '0')
				break ;
		}
		res = check_int_range(res, *argv_input, flag, ps);
		argv_input++;
	}
	return (1);
}

int	check_int_range(int res, char argv_input, int flag, t_push_swap *ps)
{
	if (!ft_isdigit(argv_input))
		error(ps);
	if (res > INT_MAX / 10 || res < INT_LOW / 10)
		error(ps);
	else if (res == INT_MAX / 10 && argv_input - '0' > 7)
		error(ps);
	else if (res == INT_LOW / 10 && argv_input - '0' > 8)
		error(ps);
	res = res * 10 + flag * (argv_input - '0');
	return (res);
}
