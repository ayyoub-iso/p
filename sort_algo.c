/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharfat <akharfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 18:42:02 by akharfat          #+#    #+#             */
/*   Updated: 2024/08/02 17:54:39 by akharfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_push_b(t_stack **a, t_stack **b)
{
	int	i;
	int	len;

	i = 0;
	len = stack_len(*a);
	if (len > 50 && len < 150)
		len /= 7;
	else if (len > 150)
		len /= 15;
	while (*a)
	{
		if ((*a)->index <= i)
		{
			pb(a, b);
			i++;
		}
		else if ((*a)->index <= (i + len))
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else
			ra(a);
	}
}

int	get_index(t_stack *stack, int rank)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (rank == stack->index)
			return (i);
		i++;
		stack = stack -> next;
	}
	return (-1);
}

void	sort_push_a(t_stack **a, t_stack **b)
{
	int	size;
	int	index;

	while (*b)
	{
		size = stack_len(*b);
		index = get_index(*b, size);
		if (index > size / 2)
		{
			while ((*b)->index != size)
				rrb(b);
		}
		else
		{
			while ((*b)->index != size)
				rb(b);
		}
		pa(b, a);
	}
}

void	algo(t_stack **a, t_stack **b)
{
	sort_push_b(a, b);
	sort_push_a(a, b);
}

void	sort(t_stack **a, t_stack *b)
{
	if (stack_len(*a) == 2)
		sa(a);
	else if (stack_len(*a) == 3)
		alg_tree(a);
	else if (stack_len(*a) == 4)
		alg_four(a, &b);
	else if (stack_len(*a) == 5)
		alg_five(a, &b);
	else
		algo(a, &b);
}
