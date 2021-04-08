/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instructions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 10:30:42 by kbenlyaz          #+#    #+#             */
/*   Updated: 2021/04/06 16:36:55 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_to(t_ll *src, t_ll *dst, int len, int write_mode)
{
	int	l;
	int	i;

	if ((len && src[0] == LL_MAX) || len == 0)
		return (1);
	l = len_number_in_stack(dst, len);
	while (l > 0)
	{	
		dst[l] = dst[l - 1];
		l--;
	}
	dst[0] = src[0];
	l = len_number_in_stack(src, len);
	i = 0;
	while (i < l - 1)
	{
		src[i] = src[i + 1];
		i++;
	}
	src[i] = LL_MAX;
	if (write_mode)
		print_operation(0, write_mode);
	return (1);
}

int	swap(t_ll *stack, int write_mode)
{
	t_ll	var_0;
	t_ll	var_1;

	var_0 = stack[0];
	var_1 = stack[1];
	stack[0] = var_1;
	stack[1] = var_0;
	if (write_mode)
		print_operation(1, write_mode);
	return (1);
}

int	rev_rotate(t_ll *stack, int len, int write_mode)
{
	t_ll	last;
	int		l;

	l = len_number_in_stack(stack, len);
	last = stack[l - 1];
	l--;
	while (l > 0)
	{	
		stack[l] = stack[l - 1];
		l--;
	}
	if (write_mode)
		print_operation(3, write_mode);
	stack[0] = last;
	return (1);
}

int	rotate(t_ll *stack, int len, int write_mode)
{
	t_ll	ferst;
	int		l;
	int		i;

	l = len_number_in_stack(stack, len);
	ferst = stack[0];
	i = 0;
	while (i < l - 1)
	{	
		stack[i] = stack[i + 1];
		i++;
	}
	stack[l - 1] = ferst;
	if (write_mode)
		print_operation(2, write_mode);
	return (1);
}

int	s_swap(t_ll *stack_a, t_ll *stack_b, int write_mode)
{
	swap(stack_a, 0);
	swap(stack_b, 0);
	if (write_mode)
		print_operation(11, write_mode);
	return (1);
}
