/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 08:14:04 by kbenlyaz          #+#    #+#             */
/*   Updated: 2021/04/07 14:01:47 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	int		ls1;
	int		ls2;
	int		i;

	if ((s1 == 0) || (s2 == 0))
		return (0);
	ls1 = len(s1);
	ls2 = len(s2);
	i = -1;
	ret = malloc(sizeof(char) * (ls1 + ls2 + 1));
	while (++i < ls1)
		*(ret + i) = *(s1 + i);
	i = 0;
	while (i < ls2)
	{
		*(ret + i + ls1) = *(s2 + i);
		i++;
	}
	*(ret + i + ls1) = '\0';
	free(s1);
	return (ret);
}

char	*line_ret(char *input, char *opr, char *get)
{
	input = ft_strjoin(input, opr);
	free(opr);
	free(get);
	return (input);
}

char	*get_line(void)
{
	char	*get;
	char	*input;
	char	*opr;
	int		count;

	count = 0;
	input = malloc(1);
	get = malloc(1);
	opr = malloc(1);
	*opr = '\0';
	*input = '\0';
	while (read(0, get, 1))
	{
		if (get[0] == '\n')
		{
			if (!check_cmd(opr, 0))
				ft_exit();
			input = ft_strjoin(input, opr);
			input = ft_strjoin(input, "\n");
			*opr = '\0';
			count++;
		}
		else
			opr = ft_strjoin(opr, get);
	}
	printf("%d\n", count);
	return (line_ret(input, opr, get));
}

int	result(t_struct strct)
{
	if (is_sorted(strct.stack_a, strct.len)
		&& !len_number_in_stack(strct.stack_b, strct.len))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_struct	strct;
	int			i;
	char		*instrct;

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
	if (strct.len == 0)
		return (1);
	check_duplicate(&strct);
	change_numbers_by_indx(&strct);
	instrct = get_line();
	check_operations(instrct);
	execute_oper(instrct, &strct);
	result(strct);
	return (0);
}
