/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:28:12 by kbenlyaz          #+#    #+#             */
/*   Updated: 2021/04/07 14:01:05 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ll	get_max(t_ll *stack, int l)
{
	t_ll	mx;
	int		check;
	int		i;
	t_ll	num;

	check = 0;
	mx = 0;
	i = 0;
	while (stack[i] != LL_MAX && i < l)
	{
		num = stack[i];
		if (num > mx || !check)
		{
			mx = num;
			check = 1;
		}
		i++;
	}
	return (mx);
}

t_ll	get_max_in_range(t_ll *stack, int l, int range)
{
	t_ll	mx;
	int		check;
	int		i;
	t_ll	num;

	check = 0;
	mx = 0;
	i = 0;
	while (stack[i] != LL_MAX && i < l && i < range)
	{
		num = stack[i];
		if (num > mx || !check)
		{
			mx = num;
			check = 1;
		}	
		i++;
	}
	return (mx);
}

int	get_index_of_value(t_ll *stack_b, t_ll value, int ln)
{
	int	i;

	i = 0;
	while (i < ln && stack_b[i] != LL_MAX)
	{
		if (stack_b[i] == value)
			return (i);
		i++;
	}
	return (0);
}

int	print_stack(t_ll *stack, int len, int index)
{
	int	i;

	i = 0;
	printf("[%d] ", index);
	while (i < len && stack[i] != LL_MAX)
	{
		printf(" %lld ", stack[i]);
		i++;
	}
	printf("\n");
	return (0);
}

int	len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
