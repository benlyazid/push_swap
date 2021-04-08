/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_range.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 15:59:03 by kbenlyaz          #+#    #+#             */
/*   Updated: 2021/04/07 11:44:46 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	sort_more_than_100_number_2(t_struct *strct, int rpt, int j, int r)
{
	if (((int)(strct->len / 100)) % 100)
	{
		r = strct->len % 100;
		r = ((int)(r / 10)) + 1;
		initial_stack(strct->stack_a, strct->stack_b, j, strct->len);
		j = 1;
		while (j < r)
		{
			set_the_10_5_nbr(strct->stack_a, strct->stack_b, rpt,
				strct->len);
			sort_5_nbr_in_2_stk(strct->stack_a, strct->stack_b,
				strct->len);
			finish_sorting(strct->stack_a, strct->stack_b, strct->len);
			rpt++;
			j++;
		}
	}
	return (1);
}

int	sort_more_than_100_number(t_struct *strct)
{
	int	j;
	int	rpt;
	int	i;

	j = 1;
	rpt = 1;
	while (j < (int)(strct->len / 100) + 1)
	{
		i = 1;
		initial_stack(strct->stack_a, strct->stack_b, j, strct->len);
		while (i < 11)
		{
			set_the_10_5_nbr(strct->stack_a, strct->stack_b,
				rpt, strct->len);
			sort_5_nbr_in_2_stk(strct->stack_a, strct->stack_b,
				strct->len);
			finish_sorting(strct->stack_a, strct->stack_b, strct->len);
			rpt++;
			i++;
		}
		j++;
	}
	sort_more_than_100_number_2(strct, rpt, j, 0);
	return (1);
}

int	sort_more_than_10_number(t_struct *strct)
{
	int	rpt;
	int	moves;
	int	i;
	int	r;

	i = 1;
	moves = 0;
	rpt = 1;
	r = ((int)(strct->len / 10));
	r++;
	moves += initial_stack(strct->stack_a, strct->stack_b, 1, strct->len);
	while (i < r)
	{
		set_the_10_5_nbr(strct->stack_a, strct->stack_b,
			rpt, strct->len);
		moves += sort_5_nbr_in_2_stk(strct->stack_a, strct->stack_b,
				strct->len);
		moves += finish_sorting(strct->stack_a, strct->stack_b, strct->len);
		rpt++;
		i++;
	}
	return (moves);
}

int	sort_more_than_5_number(t_struct *strct)
{
	int	moves;
	int	i;

	moves = 0;
	i = 0;
	while (i < strct->len)
	{
		moves += sort_last_number_by_index(strct->stack_a, i, strct->len, 1);
		i++;
	}
	return (moves);
}
