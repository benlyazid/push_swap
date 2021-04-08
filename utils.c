/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 09:16:11 by kbenlyaz          #+#    #+#             */
/*   Updated: 2021/04/06 16:31:13 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	ft_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

long long	ft_atoi_2(const char *num, int i, t_ll x, t_ll s)
{
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
			ft_exit();
		i++;
	}
	return (x * (int)s);
}

long long	ft_atoi(const char *num)
{
	long		i;
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
		if (num[i] == '\0')
			ft_exit();
	}
	while (num[i] == '0')
		i++;
	return (ft_atoi_2(num, i, x, s));
}

int	change_numbers_by_indx(t_struct *strct)
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

int	len_number_in_stack(t_ll *stack, int l)
{
	int	i;

	i = 0;
	while (stack[i] != LL_MAX && l > i)
	{
		i++;
	}
	return (i);
}
