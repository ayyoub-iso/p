/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_alg_five.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharfat <akharfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:47:53 by akharfat          #+#    #+#             */
/*   Updated: 2024/08/02 18:56:43 by akharfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_smallest_position(t_stack *stack, t_stack *smallest)
{
	int	position;

	position = 0;
	while (stack)
	{
		if (stack == smallest)
			break ;
		position++;
		stack = stack->next;
	}
	return (position);
}

void	alg_five(t_stack **a, t_stack **b)
{
	t_stack	*small;
	int		pos;
	int		len;

	small = find_smallest(*a);
	pos = find_smallest_position(*a, small);
	len = stack_len(*a);
	if (pos <= len / 2)
	{
		while (*a != small)
			ra(a);
	}
	else
	{
		while (*a != small)
			rra(a);
	}
	pb(a, b);
	alg_four(a, b);
	pa(a, b);
}
