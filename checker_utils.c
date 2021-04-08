/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:48:40 by kbenlyaz          #+#    #+#             */
/*   Updated: 2021/04/06 17:17:08 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	run_cmd(int id, t_struct *strct)
{
	if (id == PA)
		push_to(strct->stack_b, strct->stack_a, strct->len, 0);
	if (id == PB)
		push_to(strct->stack_a, strct->stack_b, strct->len, 0);
	if (id == SA)
		swap(strct->stack_a, 0);
	if (id == SB)
		swap(strct->stack_b, 0);
	if (id == SS)
		s_swap(strct->stack_a, strct->stack_b, 0);
	if (id == RA)
		rotate(strct->stack_a, strct->len, 0);
	if (id == RB)
		rotate(strct->stack_b, strct->len, 0);
	if (id == RR)
		s_rotate(strct->stack_a, strct->stack_b, strct->len, 0);
	if (id == RRA)
		rev_rotate(strct->stack_a, strct->len, 0);
	if (id == RRB)
		rev_rotate(strct->stack_b, strct->len, 0);
	if (id == RRR)
		s_rev_rotate(strct->stack_b, strct->stack_a, strct->len, 0);
	return (1);
}

int	get_operation(char *oper, int idx)
{
	int	i;
	int	rtn;
	int	count;

	count = 2;
	rtn = 0;
	i = idx;
	while (oper[i] && oper[i] != '\n')
	{
		rtn += (oper[i] * count);
		count++;
		i++;
	}
	return (rtn);
}

int	execute_oper(char *instrct, t_struct *strct)
{
	int	i;
	int	id;

	i = 0;
	while (instrct[i])
	{
		if (instrct[i] != '\n')
		{
			id = get_operation(instrct, i);
			run_cmd(id, strct);
		}
		while (instrct[i] && instrct[i] != '\n')
			i++;
		i++;
	}
	return (1);
}

int	check_cmd(char *line, int i)
{
	if (line[i] == '\n' && (i != 0 && line[i - 1] != '\n'))
		return (1);
	if (line[i] == 's' && line[i + 1] && (line[i + 1] == 's' || line[i + 1]
			== 'a' || line[i + 1] == 'b') && (line[i + 2] == '\0'
			|| line[i + 2] == '\n'))
		return (1);
	if (line[i] == 'p' && line[i + 1] && (line[i + 1] == 'a' || line[i + 1]
			== 'b') && (line[i + 2] == '\0' || line[i + 2] == '\n'))
		return (1);
	if (line[i] == 'r' && line[i + 1] && (line[i + 1] == 'r' || line[i + 1]
			== 'a' || line[i + 1] == 'b') && (line[i + 2] == '\0'
			|| line[i + 2] == '\n'))
		return (1);
	if (line[i] == 'r' && line[i + 1] && (line[i + 1] == 'r') && (line[i + 2]
			== 'r' || line[i + 2] == 'a' || line[i + 2] == 'b') && (line[i + 3]
			== '\0' || line[i + 3] == '\n'))
		return (1);
	return (0);
}

int	check_operations(char *instrct)
{
	int	i;

	i = 0;
	while (instrct[i])
	{
		if (!check_cmd(instrct, i))
		{
			ft_exit();
		}
		while (instrct [i] && instrct[i] != '\n')
		{
			i++;
		}
		i++;
	}
	return (1);
}
