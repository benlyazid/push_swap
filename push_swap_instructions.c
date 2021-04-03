/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instructions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 10:30:42 by kbenlyaz          #+#    #+#             */
/*   Updated: 2021/04/03 09:00:24 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_to(ll *src, ll *dst, int len)
{
	int	l;
	int	i;

	l = len_number_in_stack(dst, len);
	while (l > 0)
	{	
		dst[l] = dst[l - 1];
		l--;
	}
	dst[0] = src[0];	
	l = len_number_in_stack(src, len);
	i = 0;
	//print_stack(src, len, 20);
	while (i < l - 1)
	{
		src[i] = src[i + 1];
		i++;
		//print_stack(src, len, 20);

		
	}
	src[i] = LL_MAX;
	
	return (1);
}

int	swap(ll *stack)
{
	ll	var_0;
	ll	var_1;

	var_0 = stack[0];
	var_1 = stack[1];
	stack[0] = var_1; 
	stack[1] = var_0;
	return (1);
}

int	rev_rotate(ll *stack, int len)
{
	ll last;
	int	l;

	l = len_number_in_stack(stack, len);
	last = stack[l - 1];
	l--;
	while (l > 0)
	{	
		stack[l] = stack[l - 1];
		l--;
	}
	stack[0] = last;
	return (1);	
}

int	rotate(ll *stack, int len)
{
	ll ferst;
	int	l;
	int	i;

	l = len_number_in_stack(stack, len);
	ferst = stack[0];
	i = 0;
	while (i < l - 1)
	{	
		stack[i] = stack[i + 1];
		i++;
	}
	stack[l - 1] = ferst;
	return (1);
}

int	s_swap(ll *stack_a, ll *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	return (1);
}

int	s_rotate(ll *stack_a, ll *stack_b, int len)
{
	rotate(stack_a, len);
	rotate(stack_b, len);
	return (1);
}

int	s_rev_rotate(ll *stack_a, ll *stack_b, int len)
{
	rev_rotate(stack_a, len);
	rev_rotate(stack_b, len);
	return (1);
}