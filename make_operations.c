/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 10:59:32 by kbenlyaz          #+#    #+#             */
/*   Updated: 2021/04/02 18:12:55 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int		exec_operation(ll *stack_a, ll *stack_b, int oper, int	stack_index, int len)
{
	int		moves;

	moves = 0;
	if (stack_index == 3)
	{
		if (oper == 1)
			moves += s_swap(stack_a, stack_b);
		if (oper == 2)
			moves += s_rotate(stack_a, stack_b, len);
		if (oper == 3)
			moves += s_rev_rotate(stack_a, stack_b, len);
	}
	if (stack_index == 2)
	{
		if (oper == 1)
			moves += swap(stack_b);
		if (oper == 2)
			moves += rotate(stack_b, len);
		if (oper == 3)
			moves += rev_rotate(stack_b, len);
	}
	if (stack_index == 1)
		if (oper == 1)
			moves += swap(stack_a);
		if (oper == 2)
			moves += rotate(stack_a, len);
		if (oper == 3)
			moves += rev_rotate(stack_a, len);
	return (moves);
}

int		chose_operation(char *a_oper, char *b_oper, int a_i, int b_i, int depth, int ln)
{
	int	l_a;
	int	l_b;
	int	a_rtrn;
	int	b_rtrn;

	l_a = len(a_oper);
	l_b = len(b_oper);
	if (l_b > b_i &&  a_i + 1 < l_a && a_oper[a_i + 1] == b_oper[b_i])
		return (1);
	if (l_a > a_i && b_i + 1 < l_b && a_oper[a_i] == b_oper[b_i + 1])
		return (2);
	if (depth == 1)
	{
		a_rtrn = chose_operation(a_oper, b_oper, a_i + 1, b_i, 2, ln);
		b_rtrn = chose_operation(a_oper, b_oper, a_i, b_i + 1, 2, ln);
		if (a_rtrn)
			return a_rtrn;
		if (b_rtrn)
			return b_rtrn;
	}
	if (l_a > a_i)
		return (1);
	if (l_b > b_i)
		return (2);
	return (0);
}

int		make_operation(ll *stack_a, ll *stack_b, char *a_opr, char *b_opr, int ln)
{
	int	moves;
	int	i_a;
	int	i_b;
	int	chose;

	i_a = 0;
	i_b = 0;
	moves = 0;
	while (i_a < len(a_opr) || i_b < len(b_opr))
	{
		if (i_a < len(a_opr) && i_b < len(b_opr) && a_opr[i_a] == b_opr[i_b])
		{
			moves += exec_operation(stack_a, stack_b, a_opr[i_a], 3, ln);
			i_a++;
			i_b++;
		}
		else
		{
			chose = chose_operation(a_opr, b_opr, i_a, i_b, 1, ln);
			if (chose == 3 || chose == 1)
			{
				moves += exec_operation(stack_a, stack_b, a_opr[i_a], chose, ln);
				i_a++;
			}	
			if (chose == 3 || chose == 2)
			{
				moves += exec_operation(stack_a, stack_b, b_opr[i_b], chose, ln);
				i_b++;
			}
		}
	}
	return(moves);
}