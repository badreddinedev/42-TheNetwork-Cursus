/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:18:44 by bamsyah           #+#    #+#             */
/*   Updated: 2023/12/04 12:00:23 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	*sort_tab(int *tab, int size)
{
	int	loop;
	int	j;
	int	temp;

	loop = 0;
	temp = 0;
	while (loop < size)
	{
		j = loop + 1;
		while (j < size)
		{
			if (tab[loop] > tab[j])
			{
				temp = tab[loop];
				tab[loop] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		loop++;
	}
	return (tab);
}

int	*push_tab(t_stack *stack_a)
{
	int	*tab;
	int	size;
	int	loop;

	loop = 0;
	size = ft_sizeliste(stack_a);
	tab = malloc(sizeof(int) * size);
	while (stack_a)
	{
		tab[loop] = stack_a->value;
		stack_a = stack_a->next;
		loop++;
	}
	return (sort_tab(tab, size));
}
