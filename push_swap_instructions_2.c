/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instructions_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:28:46 by kbenlyaz          #+#    #+#             */
/*   Updated: 2021/04/06 17:08:27 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	s_rotate(t_ll *stack_a, t_ll *stack_b, int len, int write_mode)
{
	rotate(stack_a, len, 0);
	rotate(stack_b, len, 0);
	if (write_mode)
		print_operation(22, write_mode);
	return (1);
}

int	s_rev_rotate(t_ll *stack_a, t_ll *stack_b, int len, int write_mode)
{
	rev_rotate(stack_a, len, 0);
	rev_rotate(stack_b, len, 0);
	if (write_mode)
		print_operation(33, write_mode);
	return (1);
}
