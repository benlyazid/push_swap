/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 08:57:36 by kbenlyaz          #+#    #+#             */
/*   Updated: 2021/04/07 14:01:28 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(t_struct *strct)
{
	int	moves;

	moves = 0;
	if (is_sorted(strct->stack_a, strct->len))
		return (moves);
	if (strct->len > 100)
		moves += sort_more_than_100_number(strct);
	else
	{
		if (strct->len > 50)
			sort_100_number_or_less(strct);
		else if (strct->len > 10)
			moves += sort_more_than_10_number(strct);
		else if (strct->len > 5)
			moves += sort_more_than_5_number(strct);
		else if (strct->len <= 3)
			moves += sort_less_than_3_number(strct->stack_a, strct->len);
		else if (strct->len <= 5)
			moves += sort_less_than_5_number(strct->stack_a,
					strct->stack_b, strct->len);
	}
	if (len_number_in_stack(strct->stack_b, strct->len))
		moves += finish_number_stack_b(strct->stack_a,
				strct->stack_b, strct->len);
	return (moves);
}

int	main(int argc, char *argv[])
{
	t_struct	strct;
	int			i;

	strct.stack_a = malloc(sizeof(t_ll) * (argc - 1));
	strct.stack_b = malloc(sizeof(t_ll) * (argc - 1));
	strct.numbers = malloc(sizeof(t_ll) * (argc - 1));
	i = 0;
	while (++i < argc)
	{
		strct.numbers[i - 1] = (t_ll)ft_atoi(argv[i]);
		strct.stack_b[i - 1] = LL_MAX;
		strct.stack_a[i - 1] = LL_MAX;
	}
	strct.len = i - 1;
	check_duplicate(&strct);
	change_numbers_by_indx(&strct);
	push_swap(&strct);
	return (0);
}
