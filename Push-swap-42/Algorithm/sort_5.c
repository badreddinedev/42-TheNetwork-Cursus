/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:33:36 by bamsyah           #+#    #+#             */
/*   Updated: 2023/12/03 19:30:52 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	min;

	while (ft_sizeliste(*stack_a) > 3)
	{
		min = ft_min(*stack_a);
		if ((*stack_a)->value == min)
			pb(stack_a, stack_b);
		else if ((*stack_a)->next->value == min)
		{
			sa(stack_a);
			pb(stack_a, stack_b);
		}
		else if (ft_lastnode(stack_a).value == min)
		{
			rra(stack_a);
			pb(stack_a, stack_b);
		}
		else
			ra(stack_a);
	}
}

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	int	min;

	move_to_b(stack_a, stack_b);
	sort_3(stack_a);
	while (*stack_b)
	{
		min = ft_min(*stack_a);
		if ((*stack_a)->value < min)
			ra(stack_a);
		pa(stack_a, stack_b);
	}
}
