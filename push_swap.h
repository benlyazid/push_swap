/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 08:55:24 by kbenlyaz          #+#    #+#             */
/*   Updated: 2021/04/02 16:35:14 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>

#define LL_MAX 9223372036854775807
#define	D_MAX 2147483647
#define	D_MIN -2147483648
#define ll long long
typedef	struct s_struct
{
	ll *stack_a;
	ll *stack_b;
	ll *numbers;
	int	len;
	int	moves;
	int	reapet_100;
}			t_struct;

int			is_sorted(long long *stack, int len);
int			change_numbers_by_indx(t_struct *strct);
int			check_duplicate(t_struct *strct);
ll			ft_atoi(const char *num);
void		ft_exit();
int			len_number_in_stack(ll *stack, int len);
int			push_to(ll *src, ll *dst, int l);
int			swap(ll *stack);
int			rev_rotate(ll *stack, int l);
int			rotate(ll *stack, int len);
int			s_swap(ll *stack_a, ll *stack_b);
int			s_rotate(ll *stack_a, ll *stack_b, int len);
int			s_rev_rotate(ll *stack_a, ll *stack_b, int len);
int			sort_less_than_3_number(ll *stack, int len);
int			finish_sorting(ll *stack_a, ll *stack_b, int len);
ll			get_max(ll *stack, int l);
int			get_index_of_value(ll *stack_b, ll value, int len);
int			sort_less_than_5_number(ll *stack_a, ll *stack_b, int len);
int			print_stack(ll *stack, int len, int index);
ll			get_max_in_range(ll *stack, int l, int range);
int			initial_stack(ll *stack_a, ll *stack_b, int reapet, int len);
int			set_the_10_5_numbers(ll *stack_a, ll *stack_b, int reapet, int len);
char		*sort_number_by_index(ll *stack, int i, int len);
int			exec_operation(ll *stack_a, ll *stack_b, int oper, int	stack_index, int len);
int			len(char *str);
int			chose_operation(char *a_oper, char *b_oper, int a_i, int b_i, int depth, int ln);
int			make_operation(ll *stack_a, ll *stack_b, char *a_opr, char *b_opr, int ln);
ll			*make_stack_copy(ll *stack, int ln);
int			sort_5_number_in_2_stack(ll *stack_a, ll *stack_b, int ln);
int			sort_last_number_by_index(ll *stack, int i, int len);
int			sort_more_than_100_number(t_struct *strct);
int			sort_more_than_10_number(t_struct *strct);
int			sort_more_than_5_number(t_struct *strct);
int			finish_number_stack_b(ll *stack_a, ll *stack_b, int ln);
#endif