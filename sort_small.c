/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharfat <akharfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 18:09:47 by akharfat          #+#    #+#             */
/*   Updated: 2024/08/02 18:53:14 by akharfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*find_highest(t_stack *stack)
{
	int		highest;
	t_stack	*high;

	if (stack == NULL)
		return (NULL);
	highest = INT_MIN;
	while (stack)
	{
		if (stack->nbr > highest)
		{
			highest = stack->nbr;
			high = stack;
		}
		stack = stack->next;
	}
	return (high);
}

t_stack	*find_smallest(t_stack *stack)
{
	int		smallest;
	t_stack	*small;

	if (stack == NULL)
		return (NULL);
	smallest = INT_MAX;
	while (stack)
	{
		if (stack->nbr < smallest)
		{
			smallest = stack->nbr;
			small = stack;
		}
		stack = stack->next;
	}
	return (small);
}

void	alg_tree(t_stack **a)
{
	t_stack	*high;

	high = find_highest(*a);
	if (*a == high)
		ra(a);
	else if ((*a)->next == high)
		rra(a);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a);
}

void	alg_four(t_stack **a, t_stack **b)
{
	t_stack	*small;

	small = find_smallest(*a);
	while (*a != small)
		ra(a);
	pb(a, b);
	alg_tree(a);
	pa(a, b);
}
