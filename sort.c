/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 11:30:17 by kbenlyaz          #+#    #+#             */
/*   Updated: 2021/04/06 16:54:04 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_less_than_3_number(t_ll *stack, int ln)
{
	int		i;
	int		l;
	int		moves;
	t_ll	mx_i;

	moves = 0;
	l = len_number_in_stack(stack, ln);
	i = 0;
	while (i < l)
	{
		mx_i = get_index_of_value(stack, get_max(stack, ln), ln);
		if (l > 1 && mx_i == 0)
			moves += rotate(stack, ln, 1);
		if (l > 2 && mx_i == 1)
		{
			moves += swap(stack, 1);
			moves += rotate(stack, ln, 1);
		}
		if (l > 1 && stack[0] > stack[1])
			moves += swap(stack, 1);
		i++;
	}
	return (moves);
}

int	finish_sorting(t_ll *stack_a, t_ll *stack_b, int len)
{
	int		moves;
	int		i;

	i = 0;
	moves = 0;
	while (i < 5)
	{
		moves += rotate(stack_a, len, 1);
		i++;
	}
	i = 0;
	while (i < 5)
	{
		moves += push_to(stack_b, stack_a, len, 1);
		moves += rotate(stack_a, len, 1);
		i++;
	}
	return (moves);
}

int	sort_less_than_5_number_2(t_ll *stack_a, t_ll *stack_b, int len, int i)
{
	int	mx;
	int	index;
	int	moves;

	moves = -1;
	while (++i < len_number_in_stack(stack_a, len)
		&& len_number_in_stack(stack_b, len))
	{
		mx = get_max(stack_b, len);
		index = get_index_of_value(stack_b, mx, len);
		if (index == 1)
			moves += swap(stack_b, 2);
		if (index == 2)
			moves += rev_rotate(stack_b, len, 2);
		moves += push_to(stack_b, stack_a, len, 1);
	}
	return (moves);
}

int	sort_less_than_5_number(t_ll *stack_a, t_ll *stack_b, int len)
{
	int		i;
	t_ll	mdl;
	int		l;

	i = -1;
	l = len_number_in_stack(stack_a, len);
	mdl = (int)(len_number_in_stack(stack_a, len) / 2);
	while (++i < l)
	{
		if (stack_a[0] <= mdl)
			push_to(stack_a, stack_b, len, 2);
		else
			rotate(stack_a, len, 1);
	}
	if (len_number_in_stack(stack_a, len) > 1)
		if (stack_a[0] > stack_a[1])
			swap(stack_a, 1);
	i = -1;
	sort_less_than_5_number_2(stack_a, stack_b, len, i);
	return (1);
}

int	sort_last_number_by_index(t_ll *stack, int i, int len, int stack_index)
{
	int		rotate_count;
	int		l;
	t_ll	mx;

	l = len_number_in_stack(stack, len);
	mx = get_max_in_range(stack, l, l - i);
	if (len_number_in_stack(stack, len) == 0)
		return (0);
	rotate_count = 0;
	if (stack[l - i - 1] == mx)
		return (1);
	while (stack[0] != mx)
		rotate_count += rotate(stack, len, stack_index);
	while (rotate_count != l - 1 - i)
	{
		swap(stack, stack_index);
		rotate(stack, len, stack_index);
		rotate_count += 1;
	}
	while (rotate_count)
	{
		rev_rotate(stack, len, stack_index);
		rotate_count -= 1;
	}
	return (1);
}
