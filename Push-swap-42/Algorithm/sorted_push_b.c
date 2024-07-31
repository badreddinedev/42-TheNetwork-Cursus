/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_push_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:00:15 by bamsyah           #+#    #+#             */
/*   Updated: 2023/12/04 19:04:39 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sorted_push_b(t_stack **stack_a, t_stack **stack_b, int *tab, int chank)
{
	int	loop;
	int	size;

	loop = 0;
	size = ft_sizeliste(*stack_a);
	while (*stack_a)
	{
		if ((*stack_a)->value <= tab[loop])
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			loop++;
		}
		else if ((chank + loop) < size && (*stack_a)->value > tab[loop]
			&& (*stack_a)->value <= tab[chank + loop])
		{
			pb(stack_a, stack_b);
			loop++;
		}
		else
			ra(stack_a);
	}
}
