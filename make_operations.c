/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 10:59:32 by kbenlyaz          #+#    #+#             */
/*   Updated: 2021/04/06 16:31:13 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	exc_oprt(t_make make, int oper, int s_i, int len)
{
	if (oper == '1' && s_i == 3)
		s_swap(make.stack_a, make.stack_b, 1);
	if (oper == '2' && s_i == 3)
		s_rotate(make.stack_a, make.stack_b, len, 1);
	if (oper == '3' && s_i == 3)
		s_rev_rotate(make.stack_a, make.stack_b, len, 1);
	if (oper == '1' && s_i == 2)
		swap(make.stack_b, 2);
	if (oper == '2' && s_i == 2)
		rotate(make.stack_b, len, 2);
	if (oper == '3' && s_i == 2)
		rev_rotate(make.stack_b, len, 2);
	if (oper == '1' && s_i == 1)
		swap(make.stack_a, 1);
	if (oper == '2' && s_i == 1)
		rotate(make.stack_a, len, 1);
	if (oper == '3' && s_i == 1)
		rev_rotate(make.stack_a, len, 1);
	return (1);
}

int	chose_oper_depth(t_make make, int ln)
{
	int	a_rtrn;

	make.i_a++;
	a_rtrn = chose_operation(make, 2, ln);
	if (a_rtrn)
		return (a_rtrn);
	make.i_a--;
	make.i_b++;
	a_rtrn = chose_operation(make, 2, ln);
	make.i_b--;
	if (a_rtrn)
		return (a_rtrn);
	return (0);
}

int	chose_operation(t_make make, int depth, int ln)
{
	int	l_a;
	int	l_b;
	int	a_rtrn;

	l_a = len(make.a_opr);
	l_b = len(make.b_opr);
	if (l_b > make.i_b && make.i_a + 1 < l_a && make.a_opr[make.i_a + 1]
		== make.b_opr[make.i_b])
		return (1);
	if (l_a > make.i_a && make.i_b + 1 < l_b && make.a_opr[make.i_a]
		== make.b_opr[make.i_b + 1])
		return (2);
	if (depth == 1)
		a_rtrn = chose_oper_depth(make, ln);
	if (depth == 1 && a_rtrn)
		return (a_rtrn);
	if (l_a > make.i_a)
		return (1);
	if (l_b > make.i_b)
		return (2);
	return (0);
}

int	make_operation(t_ll *stack_a, t_ll *stack_b, t_make make, int ln)
{
	int	chose;

	make.i_a = 0;
	make.i_b = 0;
	make.stack_a = stack_a;
	make.stack_b = stack_b;
	while (make.i_a < len(make.a_opr) || make.i_b < len(make.b_opr))
	{
		if (make.i_a < len(make.a_opr) && make.i_b < len(make.b_opr)
			&& make.a_opr[make.i_a] == make.b_opr[make.i_b])
		{
			exc_oprt(make, make.a_opr[make.i_a], 3, ln);
			make.i_a++;
			make.i_b++;
		}
		else
		{
			chose = chose_operation(make, 1, ln);
			if (chose == 3 || chose == 1)
				make.i_a += exc_oprt(make, make.a_opr[make.i_a], chose, ln);
			if (chose == 3 || chose == 2)
				make.i_b += exc_oprt(make, make.b_opr[make.i_b], chose, ln);
		}
	}
	return (1);
}
