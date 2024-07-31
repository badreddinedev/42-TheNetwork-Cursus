/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:12:38 by bamsyah           #+#    #+#             */
/*   Updated: 2023/12/05 14:19:56 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	free_split(char **str)
{
	int	loop;

	loop = -1;
	while (str[++loop])
		free(str[loop]);
	free(str);
}

void	check_args(int ac, char **av, t_stack **stack_a)
{
	char	**split;
	int		loop;
	int		check;
	int		count;

	loop = 0;
	while (++loop < ac)
	{
		split = ft_split(av[loop], ' ');
		count = 0;
		while (count < ft_strlen_d(split))
		{
			check = ft_atoi(split[count]);
			check_dup(*stack_a, check);
			push_end(stack_a, ft_atoi(split[count]));
			count++;
		}
		free_split(split);
	}
}

void	moves_checker(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (!ft_strcmp(str, "sa\n"))
		sa(stack_a);
	else if (!ft_strcmp(str, "sb\n"))
		sb(stack_b);
	else if (!ft_strcmp(str, "ss\n"))
		ss(stack_a, stack_b);
	else if (!ft_strcmp(str, "pa\n"))
		pa(stack_a, stack_b);
	else if (!ft_strcmp(str, "pb\n"))
		pb(stack_a, stack_b);
	else if (!ft_strcmp(str, "ra\n"))
		ra(stack_a);
	else if (!ft_strcmp(str, "rb\n"))
		rb(stack_b);
	else if (!ft_strcmp(str, "rr\n"))
		rr(stack_a, stack_b);
	else if (!ft_strcmp(str, "rra\n"))
		rra(stack_a);
	else if (!ft_strcmp(str, "rrb\n"))
		rrb(stack_b);
	else if (!ft_strcmp(str, "rrr\n"))
		rrr(stack_a, stack_b);
	else
		ft_error();
}

void	read_input(t_stack **stack_a, t_stack **stack_b)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		if (!str)
			return ;
		moves_checker(stack_a, stack_b, str);
		free(str);
		str = get_next_line(0);
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac >= 2)
	{
		check_args(ac, av, &stack_a);
		read_input(&stack_a, &stack_b);
		if (!ft_sorted(&stack_a) && stack_b == NULL)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		free_list(&stack_a);
	}
	return (0);
}
