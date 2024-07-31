/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_max_in_top.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:13:37 by bamsyah           #+#    #+#             */
/*   Updated: 2023/12/04 11:57:40 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	place_max_in_top(t_stack **stack_b)
{
	int	max_value;
	int	size;

	while (1)
	{
		max_value = ft_find_max(*stack_b);
		size = ft_sizeliste(*stack_b);
		if (max_value == 0)
			break ;
		if (max_value > size / 2)
			rrb(stack_b);
		else if (max_value <= size / 2)
			rb(stack_b);
	}
}
