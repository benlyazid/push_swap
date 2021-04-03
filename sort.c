/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 11:30:17 by kbenlyaz          #+#    #+#             */
/*   Updated: 2021/04/03 13:29:34 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_less_than_3_number(ll *stack, int ln)
{
	int	i;
	int	l;
	int	moves;
	ll	mx_i;

	moves = 0;
	l = len_number_in_stack(stack, ln);
	i = 0;
	while (i < l)
	{
		mx_i = get_index_of_value(stack, get_max(stack, ln), ln);
		if (l > 1 && mx_i == 0)
			moves += rotate(stack, ln);
		
		if (l > 1 && mx_i == 1)
		{
			moves += swap(stack);
			moves += rotate(stack, ln);
		}
		if (l > 1 && stack[0] > stack[1])
			moves += swap(stack);
		i++;
	}
	return (moves);
}

int	finish_sorting(ll *stack_a, ll *stack_b, int len)
{
	int		moves;
	int		i;

	i = 0;
	moves = 0;
	while (i < 5)
	{
		moves += rotate(stack_a, len);
		i++;
	}
	i = 0;
	while (i < 5)
	{
		moves += push_to(stack_b, stack_a, len);
		moves += rotate(stack_a, len);
		i++;
	}
	return (moves);
}

int	sort_less_than_5_number(ll *stack_a, ll *stack_b, int len)
{
	int	i;
	ll	mdl;
	int	l;
	ll	mx;
	int	index;
	int	moves;

	moves = 0;
	i = 0;
	l = len_number_in_stack(stack_a, len);
	mdl = (int)(l / 2);
	while (i < l)
	{
		if (stack_a[0] <= mdl)
		{
			moves += push_to(stack_a, stack_b, len);
		}
		else
		{
			moves += rotate(stack_a, len);
		}
		i += 1;
	}
	if (len_number_in_stack(stack_a, len) > 1)
		if (stack_a[0] > stack_a[1])
			moves += swap(stack_a);
	i = 0;
	while (i < len_number_in_stack(stack_a, len) && len_number_in_stack(stack_b, len))
	{
		mx = get_max(stack_b, len);
		index = get_index_of_value(stack_b, mx, len);
		if (index == 1)
			moves += swap(stack_b);
		if (index == 2)
			moves += rev_rotate(stack_b, len);
		moves += push_to(stack_b, stack_a, len);
		i += 1;
	}
	return(moves);
}

int	sort_last_number_by_index(ll *stack, int i, int len)
{
	ll	mx;
	int	rotate_count;
	int moves;
	int	l;
	printf("start sorting\n");
	print_stack(stack, len, mx);
	l = len_number_in_stack(stack, len);
	moves = 0;
	if (len_number_in_stack(stack, len) == 0)
		return (0);
	mx = get_max_in_range(stack, l, l - i);
	rotate_count = 0;
	if (stack[l - i - 1] == mx)
		return (1);
	while (stack[0] != mx)
	{
		moves += rotate(stack, len);
		rotate_count += 1;
	}	

	while( rotate_count != l - 1 - i)
	{
		moves += swap(stack);
		moves += rotate(stack, len);
		rotate_count += 1;
	}

	while (rotate_count)
	{
		moves += rev_rotate(stack, len);
		rotate_count -= 1;
	}
	printf("end sorting %d\n", moves);
	return(moves);
}

int			finish_number_stack_b(ll *stack_a, ll *stack_b, int ln)
{
	int	i;
	int	moves;
	int	l;

	i = 0;
	moves = 0;

	while (i < len_number_in_stack(stack_b, ln))
	{
		moves += sort_last_number_by_index(stack_b, i, ln);
		i++;
	}
	
	i = 0;	
	print_stack(stack_b, ln, moves);
	l = len_number_in_stack(stack_b, ln);
	while (i < l)
	{
		moves += push_to(stack_b, stack_a, ln);
		moves += rotate(stack_a, ln);		
		i++;
	}
	//printf("finish number in [%d] and l is %d\n", moves, l);
	
	return (moves);
}