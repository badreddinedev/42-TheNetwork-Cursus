/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:17:57 by bamsyah           #+#    #+#             */
/*   Updated: 2023/12/03 20:43:01 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_find_max(t_stack *stack)
{
	int	max_value;
	int	max_index;
	int	loop;

	loop = 0;
	max_index = 0;
	max_value = stack->value;
	while (stack)
	{
		if (max_value < stack->value)
		{
			max_value = stack->value;
			max_index = loop;
		}
		stack = stack->next;
		loop++;
	}
	return (max_index);
}
