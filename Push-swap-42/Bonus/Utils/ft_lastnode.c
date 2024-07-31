/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lastnode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:24:36 by bamsyah           #+#    #+#             */
/*   Updated: 2023/12/04 12:00:13 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

t_stack	ft_lastnode(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last;

	temp = *stack;
	while (temp->next)
		temp = temp->next;
	last = temp;
	return (*last);
}
