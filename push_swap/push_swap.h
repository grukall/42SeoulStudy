/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:35:50 by seungule          #+#    #+#             */
/*   Updated: 2023/09/28 20:18:45 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# define INT_MAX 2147483647
# define INT_LOW -2147483648

typedef struct s_push_swap
{
	int	*stack_a;
	int	*stack_b;
	int	len;
	int	stack_count[2];
	int	num;
	int	pivot[3];
	int	biggest;
	int	biggest_index;
}t_push_swap;

int		push_stack(t_push_swap *ps, char **result, int index);
int		error(t_push_swap *ps);
int		check_argv(char *argv_input, t_push_swap *ps);
void	parsing(t_push_swap *ps, char **argv);
void	free_stack(t_push_swap *ps);
int		check_len(char **argv);

int		sa(t_push_swap *ps);
int		sb(t_push_swap *ps);
int		ss(t_push_swap *ps);
int		pa(t_push_swap *ps);
int		pb(t_push_swap *ps);
int		ra(t_push_swap *ps);
int		rb(t_push_swap *ps);
int		rr(t_push_swap *ps);
int		rra(t_push_swap *ps);
int		rrb(t_push_swap *ps);
int		rrr(t_push_swap *ps);

int		before_push_swap(t_push_swap *ps);
void	sort_third2(t_push_swap *ps);
void	sort_forth(t_push_swap *ps);
int		push_swap(t_push_swap *ps);
int		is_sort_a(t_push_swap *ps);

void	average_num(t_push_swap *ps);
void	average_num2(t_push_swap *ps);
void	sort_a(t_push_swap *ps, int *stack);
int		where_next_num(t_push_swap *ps, int stack_top_b);
int		where_biggest_num(t_push_swap *ps);

void	stack_top_b_is_biggest(t_push_swap *ps, int stack_top_b);

void	less_than_5(t_push_swap *ps);
void	less_than_500(t_push_swap *ps);
void	greater_than_500(t_push_swap *ps);
void	sort_first(t_push_swap *ps);
void	sort_second(t_push_swap *ps);
void	sort_third(t_push_swap *ps);

void	quicksort(int arr[], int low, int high);

#endif