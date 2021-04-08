/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 08:25:45 by kbenlyaz          #+#    #+#             */
/*   Updated: 2021/04/07 14:00:35 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	initial_stack(t_ll *stack_a, t_ll *stack_b, int reapet, int len)
{
	int	range;
	int	range_min;
	int	rotate_count;
	int	count;

	count = 0;
	rotate_count = 0;
	range = reapet * 100;
	range_min = range - 100;
	while (len_number_in_stack(stack_a, len)
		&& len_number_in_stack(stack_b, len) != 100)
	{
		if (stack_a[0] < range && stack_a[0] >= range_min)
			push_to(stack_a, stack_b, len, 2);
		else
			rotate_count += rotate(stack_a, len, 1);
		count += 1;
		if (len_number_in_stack(stack_a, len) == 0 || count > len
			|| range_min > stack_a[0])
			break ;
	}
	rotate_count++;
	while (--rotate_count)
		rev_rotate(stack_a, len, 1);
	return (1);
}

void	set_the_10_5_nbr(t_ll *stack_a, t_ll *stack_b, int reapet, int len)
{
	int	range;
	int	count;
	int	rotate_count;

	rotate_count = 0;
	range = reapet * 10;
	count = 0;
	while (count < 10 && len_number_in_stack(stack_b, len))
	{
		if (stack_b[0] < range)
			count += push_to(stack_b, stack_a, len, 1);
		else
			rotate(stack_b, len, 2);
	}
	count = 0;
	while (len_number_in_stack(stack_a, len) && count < 5)
	{
		if (stack_a[0] >= range - 5 && stack_a[0] < range)
			count += push_to(stack_a, stack_b, len, 2);
		else
			rotate_count += rotate(stack_a, len, 1);
	}
	rotate_count++;
	while (--rotate_count)
		rev_rotate(stack_a, len, 1);
}

int	sort_5_nbr_in_2_stk(t_ll *stack_a, t_ll *stack_b, int ln)
{
	int			i;
	t_ll		*stack_a_cp;
	t_ll		*stack_b_cp;
	t_make		make;

	i = 0;
	while (i < 5)
	{
		stack_a_cp = make_stack_copy(stack_a, ln);
		stack_b_cp = make_stack_copy(stack_b, ln);
		make.a_opr = sort_number_by_index(stack_a_cp, i, ln);
		make.b_opr = sort_number_by_index(stack_b_cp, i, ln);
		make_operation(stack_a, stack_b, make, ln);
		free(stack_a_cp);
		free(stack_b_cp);
		free(make.a_opr);
		free(make.b_opr);
		i++;
	}
	return (1);
}

int	sort_number_by_index_2(t_ll *stack, int len, t_arg *arg, char *oper)
{
	int	index;

	index = arg->index;
	while (arg->rotate_count != 4 - arg->i)
	{
		swap(stack, 0);
		oper[++index] = '1';
		arg->rotate_count += rotate(stack, len, 0);
		oper[++index] = '2';
	}
	while (arg->rotate_count)
	{
		arg->rotate_count -= rev_rotate(stack, len, 0);
		oper[++index] = '3';
	}
	return (index);
}

char	*sort_number_by_index(t_ll *stack, int i, int len)
{
	char	*oper;
	int		rotate_count;
	int		index;
	t_arg	arg;

	if (!len_number_in_stack(stack, len))
		return (NULL);
	oper = malloc(sizeof(char) * 1000);
	arg.mx = get_max_in_range(stack, len, 5 - i);
	rotate_count = 0;
	index = 0;
	if (stack[4 - i] != arg.mx)
	{
		while (stack[0] != arg.mx)
		{
			oper[rotate_count] = '2';
			rotate_count += rotate(stack, len, 0);
		}
		arg.index = rotate_count - 1;
		arg.rotate_count = rotate_count;
		arg.i = i;
		index = sort_number_by_index_2(stack, len, &arg, oper);
	}
	oper[++index] = '\0';
	return (oper);
}
