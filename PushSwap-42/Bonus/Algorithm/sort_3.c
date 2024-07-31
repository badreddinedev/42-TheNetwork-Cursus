/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:22:33 by bamsyah           #+#    #+#             */
/*   Updated: 2023/12/04 11:57:47 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	sort_3(t_stack **stack_a)
{
	int	beging;
	int	middle;
	int	last;

	beging = (*stack_a)->value;
	middle = (*stack_a)->next->value;
	last = ft_lastnode(stack_a).value;
	if (ft_sizeliste(*stack_a) == 2 && (beging > last))
		sa(stack_a);
	else if (beging > middle && middle > last)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (beging > last && last > middle)
		ra(stack_a);
	else if (middle > beging && beging > last)
		rra(stack_a);
	else if (middle > last && last > beging)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (last > beging && beging > middle)
		sa(stack_a);
}
