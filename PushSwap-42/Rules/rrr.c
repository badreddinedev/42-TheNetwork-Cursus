/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:18:08 by bamsyah           #+#    #+#             */
/*   Updated: 2023/12/03 14:03:06 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate_stack(stack_a);
	rev_rotate_stack(stack_b);
	write(1, "rrr\n", 4);
}
