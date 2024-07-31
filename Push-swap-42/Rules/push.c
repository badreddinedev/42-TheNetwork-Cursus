/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 18:22:57 by bamsyah           #+#    #+#             */
/*   Updated: 2023/12/05 14:39:32 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_end(t_stack **stack, int value)
{
	t_stack	*new_node;
	t_stack	*temp;

	temp = *stack;
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		exit(1);
	new_node->value = value;
	new_node->next = NULL;
	if (!(*stack))
		*stack = new_node;
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
	}
}

void	push_begin(t_stack **stack, int value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		exit(1);
	new_node->value = value;
	new_node->next = *stack;
	*stack = new_node;
}

int	pop(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*head;
	int		value;

	head = *stack;
	if (!head)
		exit (1);
	temp = head;
	value = temp->value;
	*stack = head->next;
	free(temp);
	return (value);
}

void	check_dup(t_stack *stack, int value)
{
	t_stack	*head;

	head = stack;
	while (head)
	{
		if (head->value == value)
		{
			ft_putstr_fd("Error\n", 2);
			exit (1);
		}
		head = head->next;
	}
}

void	free_list(t_stack **stack)
{
	t_stack	*head;
	t_stack	*temp;

	head = *stack;
	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
	free(head);
	*stack = NULL;
}
