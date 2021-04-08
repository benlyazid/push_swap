/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 13:59:11 by kbenlyaz          #+#    #+#             */
/*   Updated: 2021/04/07 14:00:41 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	run_in_init_mini(int rotate_count, t_ll *stack_a, int len)
{
	rotate_count++;
	while (--rotate_count)
		rev_rotate(stack_a, len, 1);
}

int	initial_mini_stack(t_ll *stack_a, t_ll *stack_b, int reapet, int len)
{
	int	range;
	int	rotate_count;
	int	count;
	int	init;

	init = (int)(len / 2);
	if (len % 2)
		init++;
	count = 0;
	rotate_count = 0;
	range = reapet * init;
	while (len_number_in_stack(stack_a, len)
		&& len_number_in_stack(stack_b, len) != init)
	{
		if (stack_a[0] < range && stack_a[0] >= range - init)
			push_to(stack_a, stack_b, len, 2);
		else
			rotate_count += rotate(stack_a, len, 1);
		count += 1;
		if (len_number_in_stack(stack_a, len) == 0 || count > len
			|| range - init > stack_a[0])
			break ;
	}
	run_in_init_mini(rotate_count, stack_a, len);
	return (1);
}

void	sort_100_number_or_less(t_struct *strct)
{
	int	rpt;
	int	i;
	int	r;
	int	k;

	i = 0;
	rpt = 1;
	r = ((int)(strct->len / 10));
	r = (((int)(r / 2))) + 1;
	if (strct->len % 20)
		r++;
	k = 0;
	while (++k < 3)
	{
		initial_mini_stack(strct->stack_a, strct->stack_b, k, strct->len);
		while (++i < r)
		{
			set_the_10_5_nbr(strct->stack_a, strct->stack_b, rpt, strct->len);
			sort_5_nbr_in_2_stk(strct->stack_a, strct->stack_b, strct->len);
			finish_sorting(strct->stack_a, strct->stack_b, strct->len);
			rpt++;
		}
		r = ((int)(strct->len / 10)) + 2;
	}
}
