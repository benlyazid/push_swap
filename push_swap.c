/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 08:57:36 by kbenlyaz          #+#    #+#             */
/*   Updated: 2021/04/02 18:38:43 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(t_struct *strct)
{
	int	moves;

	moves = 0;
	if (is_sorted(strct->stack_a, strct->len))
		return(moves);
	if (strct->len > 100)
		moves += sort_more_than_100_number(strct);
	else
	{
		if (strct->len > 10)
			moves += sort_more_than_10_number(strct);
		else if (strct->len > 5)
			moves += sort_more_than_5_number(strct);
		else if (strct->len <= 3)
			moves += sort_less_than_3_number(strct->stack_a, strct->len);
		else if (strct->len <= 5)
			moves += sort_less_than_5_number(strct->stack_a, strct->stack_b, strct->len);
		if (len_number_in_stack(strct->stack_b, strct->len))
			moves += finish_number_stack_b(strct->stack_a, strct->stack_a, strct->len);
	}
	
	return (moves);
}

int main(int argc, char *argv[], char **envp)
{
	t_struct	strct;
	int			i;
	

	strct.stack_a = malloc(sizeof(ll) * (argc - 1));
	strct.stack_b = malloc(sizeof(ll) * (argc - 1));
	strct.numbers = malloc(sizeof(ll) * (argc - 1));
	i = 0;
	while (1)
	{
		/* code */
	}
	
	while (++i < argc)
	{
		strct.numbers[i - 1] = (ll)ft_atoi(argv[i]);
		strct.stack_b[i- 1] = LL_MAX;
		strct.stack_a[i- 1] = LL_MAX;
	}
	strct.len = i - 1;
	check_duplicate(&strct);
	change_numbers_by_indx(&strct);

	int l = len_number_in_stack(strct.stack_a, strct.len);
	i = 0;
	while (i < strct.len)
	{
		printf(" [%lld] ", strct.stack_a[i]);
		i++;
	}
	printf("\n");
	
	//int m = initial_stack(strct.stack_a, strct.stack_b, 1, strct.len);
	//set_the_10_5_numbers(strct.stack_a, strct.stack_b, 1, strct.len);
	//sort_5_number_in_2_stack(strct.stack_a, strct.stack_b, strct.len);
	//finish_sorting(strct.stack_a, strct.stack_b, strct.len);
	//printf("len [%d]\n", strct.len); 
	//sort_last_number_by_index(strct.stack_a, 0, strct.len);
	push_swap(&strct);
	i = 0;
	while (i < strct.len)
	{
		printf("a [%lld] \n", strct.stack_a[i]);
		printf("b [%lld] \n", strct.stack_b[i]);
		i++;
	}
	
}