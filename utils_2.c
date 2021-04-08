/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:24:33 by kbenlyaz          #+#    #+#             */
/*   Updated: 2021/04/06 16:37:55 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate(t_struct *strct)
{
	int	i;
	int	j;

	i = 0;
	while (i < strct->len)
	{
		j = i + 1;
		while (j < strct->len)
		{
			if (strct->numbers[i] == strct->numbers[j])
				ft_exit();
			j++;
		}
		i++;
	}
	return (1);
}

int	is_sorted(long long *stack, int len)
{
	int	i;
	int	l;

	i = 0;
	l = len_number_in_stack(stack, len);
	while (i < l)
	{
		if (stack[i] != i)
			return (0);
		i++;
	}
	return (1);
}

int	print_operation(int oper, int stack)
{
	if (oper == 0)
	{
		if (stack == 1)
			write(1, "pa\n", 3);
		if (stack == 2)
			write(1, "pb\n", 3);
	}
	else if (oper == 1)
	{
		if (stack == 1)
			write(1, "sa\n", 3);
		if (stack == 2)
			write(1, "sb\n", 3);
	}
	else
		print_operation_2(oper, stack);
	return (1);
}

int	print_operation_2(int oper, int stack)
{
	if (oper == 2)
	{
		if (stack == 1)
			write(1, "ra\n", 3);
		if (stack == 2)
			write(1, "rb\n", 3);
	}
	else if (oper == 3)
	{
		if (stack == 1)
			write(1, "rra\n", 4);
		if (stack == 2)
			write(1, "rrb\n", 4);
	}
	else if (oper == 11)
		write(1, "ss\n", 3);
	else if (oper == 22)
		write(1, "rr\n", 3);
	else if (oper == 33)
		write(1, "rrr\n", 4);
	return (1);
}

t_ll	*make_stack_copy(t_ll *stack, int ln)
{
	t_ll	*cp;
	int		i;

	i = 0;
	cp = malloc(sizeof(t_ll) * ln);
	while (i < ln)
	{
		cp[i] = stack[i];
		i++;
	}
	return (cp);
}
