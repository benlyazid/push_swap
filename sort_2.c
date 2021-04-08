/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 18:04:19 by kbenlyaz          #+#    #+#             */
/*   Updated: 2021/04/07 13:34:15 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	finish_number_stack_b(t_ll *stack_a, t_ll *stack_b, int ln)
{
	int	i;
	int	moves;
	int	l;

	i = 0;
	moves = 0;
	while (i < len_number_in_stack(stack_b, ln))
	{
		moves += sort_last_number_by_index(stack_b, i, ln, 2);
		i++;
	}
	i = 0;
	l = len_number_in_stack(stack_b, ln);
	while (i < l)
	{
		moves += push_to(stack_b, stack_a, ln, 1);
		moves += rotate(stack_a, ln, 1);
		i++;
	}	
	return (1);
}
