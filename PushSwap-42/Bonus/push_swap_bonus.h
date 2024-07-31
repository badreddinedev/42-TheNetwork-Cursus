/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:49:04 by bamsyah           #+#    #+#             */
/*   Updated: 2023/12/05 13:55:16 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>
# include "./Get_next_line/get_next_line.h"
# include "./ft_printf/ft_printf.h"
# include "./Utils/libft.h"

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
void	ft_error(void);
//---------------------Rules----------------------

//---------------------Algorithm----------------------
void	algorithm(t_stack **stack_a, t_stack **stack_b);
void	sort_3(t_stack **stack_a);
void	sort_5(t_stack **stack_a, t_stack **stack_b);
void	sort_up_5(t_stack **stack_a, t_stack **stack_b, int chank);
void	sorted_push_b(t_stack **stack_a, t_stack **stack_b,
			int *tab, int chank);
void	place_max_in_top(t_stack **stack_b);
//---------------------Algorithm----------------------

//---------------------Utils----------------------
int		ft_sorted(t_stack **stack);
int		ft_sizeliste(t_stack *stack);
t_stack	ft_lastnode(t_stack **stack);
int		ft_min(t_stack *stack);
int		*push_tab(t_stack *stack_a);
int		ft_find_max(t_stack *stack);
int		ft_strcmp(char *s1, char *s2);
//---------------------Utils----------------------
#endif