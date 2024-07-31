/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_up_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:09:01 by bamsyah           #+#    #+#             */
/*   Updated: 2023/12/03 20:41:12 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_up_5(t_stack **stack_a, t_stack **stack_b, int chank)
{
	int	*tab;

	tab = push_tab(*stack_a);
	sorted_push_b(stack_a, stack_b, tab, chank);
	while (*stack_b)
	{
		place_max_in_top(stack_b);
		pa(stack_a, stack_b);
	}
	free (tab);
}
