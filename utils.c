/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 09:16:11 by kbenlyaz          #+#    #+#             */
/*   Updated: 2021/04/02 12:17:08 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void		ft_exit()
{
	write(1, "Error", 5);
	exit(1);
}

long long	ft_atoi(const char *num)
{
	long	i;
	long long	s;
	long long	x;

	i = 0;
	s = 1;
	x = 0;
	while ((num[i] >= 9 && num[i] <= 13) || num[i] == 32)
		i++;
	if (num[i] == '+' || num[i] == '-')
	{
		if (num[i] == '-')
			s = s * -1;
		i++;
	}
	while (num[i])
	{
		if (num[i] >= '0' && num[i] <= '9')
		{
			x = 10 * x + (num[i] - '0');
			if ((x * s) < -2147483648)
				ft_exit();
			if ((x * s) > 2147483647)
				ft_exit();
		}
		else
		{
			ft_exit();
		}	
		i++;
	}
	
	return (x * (int)s);
}

int		change_numbers_by_indx(t_struct *strct)
{
	int		i;
	int		j;
	int		index;

	i = 0;
	while (i < strct->len)
	{
		index = 0;
		j = 0;
		while (j < strct->len)
		{
			if (strct->numbers[i] > strct->numbers[j] && i != j)
				index++;
			
			j++;
		}
		strct->stack_a[i] = index;
		i++;
	}
	return (1);
}

int		check_duplicate(t_struct *strct)
{
	int		i;
	int		j;

	i = 0;
	while (i < strct->len)
	{
		j = i + 1;
		while (j < strct->len)
		{
			if (strct->numbers[i] == strct->numbers[j])
				ft_exit();
			j++;
		}
		i++;
	}
	return (1);
}

int		len_number_in_stack(ll *stack, int l)
{
	int	i;

	i = 0;
	while (stack[i] != LL_MAX && l > i)
	{
		i++;
	}
	return (i);
}

int		is_sorted(long long *stack, int len)
{
	int	i;
	int	l;

	i = 0;
	l = len_number_in_stack(stack, len);
	while (i < l)
	{
		if (stack[i] != i)
			return (0);
		i++;
	}
	return (1);
}

ll		get_max(ll *stack, int l)
{
	ll	mx;
	int	check;
	int i;
	ll	num;

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

ll		get_max_in_range(ll *stack, int l, int range)
{
	ll	mx;
	int	check;
	int i;
	ll	num;

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

int	get_index_of_value(ll *stack_b, ll value, int ln)
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

int			print_stack(ll *stack, int len, int index)
{
	int i = 0;

	printf("[%d] ", index);
	while (i < len && stack[i] != LL_MAX)
	{
		printf(" %lld ", stack[i]);
		i++;
	}
	printf("\n");
	return (0);
}

int		len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

ll		*make_stack_copy(ll *stack, int ln)
{
	ll		*cp;
	int		i;

	i = 0;
	cp = malloc(sizeof(ll) * ln);
	while (i < ln)
	{
		cp[i] = stack[i];
		i++;
	}
	return (cp);
}