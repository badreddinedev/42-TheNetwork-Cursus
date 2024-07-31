/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:21:04 by bamsyah           #+#    #+#             */
/*   Updated: 2023/12/05 13:55:08 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "./Utils/libft.h"
# include "./ft_printf/ft_printf.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

//---------------------Rules----------------------
void	push_end(t_stack **stack, int value);
void	push_begin(t_stack **stack, int value);
int		pop(t_stack **stack);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	swap_stack(t_stack **stack);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	rotate_stack(t_stack **stack);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rev_rotate_stack(t_stack **stack);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	check_dup(t_stack *stack, int value);
void	free_list(t_stack **stack);
//---------------------Rules----------------------

//---------------------Utils----------------------
int		ft_sorted(t_stack **stack);
int		ft_sizeliste(t_stack *stack);
t_stack	ft_lastnode(t_stack **stack);
int		ft_min(t_stack *stack);
int		*push_tab(t_stack *stack_a);
int		ft_find_max(t_stack *stack);
void	ft_error(void);
//---------------------Utils----------------------
//---------------------Algorithm----------------------
void	algorithm(t_stack **stack_a, t_stack **stack_b);
void	sort_3(t_stack **stack_a);
void	sort_5(t_stack **stack_a, t_stack **stack_b);
void	sort_up_5(t_stack **stack_a, t_stack **stack_b, int chank);
void	sorted_push_b(t_stack **stack_a, t_stack **stack_b,
			int *tab, int chank);
void	place_max_in_top(t_stack **stack_b);
//---------------------Algorithm----------------------

void	print_list(t_stack *list);
#endif