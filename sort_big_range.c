/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_range.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 15:59:03 by kbenlyaz          #+#    #+#             */
/*   Updated: 2021/04/03 13:11:38 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	initial_stack(ll *stack_a, ll *stack_b, int reapet, int len)
{
	int	range;
	int	range_min;
	int	rotate_count;
	int	moves;
	int	count;

	count = 0;
	rotate_count = 0;
	range = reapet * 100;
	range_min = range - 100;
	moves = 0;
	while (len_number_in_stack(stack_a, len) && len_number_in_stack(stack_b, len) != 100)
	{
		if (stack_a[0] < range && stack_a[0] >= range_min)
			moves += push_to(stack_a, stack_b, len);
		else
		{
				moves += rotate(stack_a, len);
				rotate_count += 1;
		}
		count += 1;
		if (len_number_in_stack(stack_a, len) == 0 || count > len || range_min > stack_a[0])
			break;
	}
	while (rotate_count)
	{
		rotate_count--;
		moves += rev_rotate(stack_a, len);
	}
	printf("initial with%d\n", reapet);
	return (moves);
}


int	set_the_10_5_numbers(ll *stack_a, ll *stack_b, int reapet, int len)
{
	int	range;
	int	count;
	int	rotate_count;
	int	moves;

	rotate_count = 0;
	range = reapet * 10;
	count = 0;
	moves = 0;
	while (count < 10 && len_number_in_stack(stack_b, len))
	{
		if (stack_b[0] < range)
		{
			moves += push_to(stack_b, stack_a, len);
			count += 1;
		}
		else
			moves += rotate(stack_b, len);
	}
	count = 0;
	range -= 5;
	while (len_number_in_stack(stack_a, len) && count < 5)
	{
		if (stack_a[0] >= range && stack_a[0] < range + 5)
		{
			moves += push_to(stack_a, stack_b, len);
			count += 1;
		}
		else
		{
			moves += rotate(stack_a, len);
			rotate_count += 1;
		}
	}

	while (rotate_count)
	{
		moves += rev_rotate(stack_a, len);
		rotate_count -= 1;
	}
	return (moves);
}

int	sort_5_number_in_2_stack(ll *stack_a, ll *stack_b, int ln)
{
	int	i;
	char	*a_opr;
	char	*b_opr;
	ll		*stack_a_cp;
	ll		*stack_b_cp;
	int		moves;
	i = 0;
	
	moves = 0;
	while (i < 5)
	{
		stack_a_cp = make_stack_copy(stack_a, ln);
		stack_b_cp = make_stack_copy(stack_b, ln);
		a_opr = sort_number_by_index(stack_a_cp, i, ln);
		b_opr = sort_number_by_index(stack_b_cp, i, ln);
		moves += make_operation(stack_a, stack_b, a_opr, b_opr, ln);
		//printf("a [%s] b[%s]\n", a_opr, b_opr);
		free(stack_a_cp);
		free(stack_b_cp);
		i++;
	}
	return (moves);
}

 /*	SHOULD_NOT_PRINT_THE_OPERATIONS	*/
char	*sort_number_by_index(ll *stack, int i, int len)
{
	char	*oper;
	int		mx;
	int		rotate_count;
	int		index;

	if (!len_number_in_stack(stack, len))
		return (NULL);
	index = -1;
	oper = malloc(sizeof(char) * 1000);
	mx = get_max_in_range(stack, len, 5 - i);
	//print_stack(stack, len, -1);
	//printf("------------------------\n");
	rotate_count = 0;
	if (stack[4 - i] != mx)
	{
		while (stack[0] != mx)
		{
			rotate(stack, len);
			oper[++index] = '2';
			rotate_count++;
		}

		while (rotate_count != 4 - i)
		{
			swap(stack);
			oper[++index] = '1';
			rotate(stack, len);
			oper[++index] = '2';
			rotate_count++;
		}
				
		while (rotate_count)
		{
			rev_rotate(stack, len);
			oper[++index] = '3';
			rotate_count -= 1;
		}
	}
	oper[++index] = '\0';
	return (oper);
}

int			sort_more_than_100_number(t_struct *strct)
{
	int	j;
	int	rpt;
	int	moves;
	int	i;
	int	r;

	moves = 0;
	j = 1;
	rpt = 1;
	while (j < (int)(strct->len / 100) + 1)
	{
		i = 1;
		moves += initial_stack(strct->stack_a, strct->stack_b, j, strct->len);
		
		while (i < 11)
		{
			moves += set_the_10_5_numbers(strct->stack_a, strct->stack_b, rpt, strct->len);
			moves += sort_5_number_in_2_stack(strct->stack_a, strct->stack_b, strct->len);
			moves += finish_sorting(strct->stack_a, strct->stack_b, strct->len);
			rpt++;
			i++;
		}
		j++;
	}
	print_stack(strct->stack_b, strct->len, 98);

	if (((int)(strct->len / 100)) % 100)
	{
		r =  strct->len % 100;
		r = ((int)(r / 10)) + 1;
		moves += initial_stack(strct->stack_a, strct->stack_b, j, strct->len);
		print_stack(strct->stack_b, strct->len, j);
		j = 1;
		while (j < r)
		{
			moves += set_the_10_5_numbers(strct->stack_a, strct->stack_b, rpt, strct->len);
			moves += sort_5_number_in_2_stack(strct->stack_a, strct->stack_b, strct->len);
			moves += finish_sorting(strct->stack_a, strct->stack_b, strct->len);
			rpt++;
			j++;
		}
	}
	
	return (moves);
}

int			sort_more_than_10_number(t_struct *strct)
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
		moves += set_the_10_5_numbers(strct->stack_a, strct->stack_b, rpt, strct->len);
		
		moves += sort_5_number_in_2_stack(strct->stack_a, strct->stack_b, strct->len);

		moves += finish_sorting(strct->stack_a, strct->stack_b, strct->len);
		
		rpt++;
		i++;
	}
	return (moves);
}

int			sort_more_than_5_number(t_struct *strct)
{
	int moves;
	int	i;

	moves = 0;
	i = 0;
	while (i < strct->len)
	{
		moves += sort_last_number_by_index(strct->stack_a, i, strct->len);
		i++;
	}
	return (moves);
}