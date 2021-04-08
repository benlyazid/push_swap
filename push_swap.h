/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 08:55:24 by kbenlyaz          #+#    #+#             */
/*   Updated: 2021/04/07 11:44:46 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <sys/types.h>
# include <stdlib.h>
# include <stdio.h>

# define LL_MAX 9223372036854775807
# define	D_MAX 2147483647
# define	D_MIN -2147483648
typedef long long	t_ll;

# define	PA 515
# define	PB 518

# define	SA 521
# define	SB 524
# define	SS 575

# define	RA 519
# define	RB 522
# define	RR 570

# define	RRA 958
# define	RRB 962
# define	RRR 1026

typedef struct s_struct
{
	t_ll	*stack_a;
	t_ll	*stack_b;
	t_ll	*numbers;
	int		len;
	int		moves;
	int		reapet_100;
	int		l;
}			t_struct;

typedef struct s_arg
{
	int	i;
	int	rotate_count;
	int	index;
	int	mx;
}			t_arg;

typedef struct s_make
{
	int		ln;
	int		rotate_count;
	t_ll	*stack_a;
	t_ll	*stack_b;
	char	*a_opr;
	char	*b_opr;
	int		i_a;
	int		i_b;
}			t_make;

int			is_sorted(long long *stack, int len);
int			change_numbers_by_indx(t_struct *strct);
int			check_duplicate(t_struct *strct);
t_ll		ft_atoi(const char *num);
void		ft_exit(void);
int			len_number_in_stack(t_ll *stack, int len);
int			push_to(t_ll *src, t_ll *dst, int l, int write_mode);
int			swap(t_ll *stack, int write_mode);
int			rev_rotate(t_ll *stack, int l, int write_mode);
int			rotate(t_ll *stack, int len, int write_mode);
int			s_swap(t_ll *stack_a, t_ll *stack_b, int write_mode);
int			s_rotate(t_ll *stack_a, t_ll *stack_b, int len, int write_mode);
int			s_rev_rotate(t_ll *stack_a, t_ll *stack_b, int len, int write_mode);
int			sort_less_than_3_number(t_ll *stack, int len);
int			finish_sorting(t_ll *stack_a, t_ll *stack_b, int len);
t_ll		get_max(t_ll *stack, int l);
int			get_index_of_value(t_ll *stack_b, t_ll value, int len);
int			sort_less_than_5_number(t_ll *stack_a, t_ll *stack_b, int len);
int			print_stack(t_ll *stack, int len, int index);
t_ll		get_max_in_range(t_ll *stack, int l, int range);
int			initial_stack(t_ll *stack_a, t_ll *stack_b, int reapet, int len);
void		set_the_10_5_nbr(t_ll *st_a, t_ll *st_b, int reapet, int len);
char		*sort_number_by_index(t_ll *stack, int i, int len);
int			exc_oprt(t_make make, int oper, int	stack_index, int len);
int			len(char *str);
int			chose_operation(t_make make, int depth, int ln);
int			make_operation(t_ll *stack_a, t_ll *stack_b, t_make make, int ln);
t_ll		*make_stack_copy(t_ll *stack, int ln);
int			sort_5_nbr_in_2_stk(t_ll *stack_a, t_ll *stack_b, int ln);
int			sort_last_number_by_index(t_ll *stk, int i, int len, int stk_idx);
int			sort_more_than_100_number(t_struct *strct);
int			sort_more_than_10_number(t_struct *strct);
int			sort_more_than_5_number(t_struct *strct);
int			finish_number_stack_b(t_ll *stack_a, t_ll *stack_b, int ln);
int			print_operation(int oper, int stack);
int			print_operation_2(int oper, int stack);
int			run_cmd(int id, t_struct *strct);
int			et_operation(char *oper, int idx);
int			execute_oper(char *instrct, t_struct *strct);
int			check_cmd(char *line, int i);
int			check_operations(char *instrct);
int			initial_mini_stack(t_ll *stack_a,
				t_ll *stack_b, int reapet, int len);
void		sort_100_number_or_less(t_struct *strct);
#endif