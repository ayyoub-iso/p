/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_after.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharfat <akharfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 18:10:15 by akharfat          #+#    #+#             */
/*   Updated: 2024/07/29 15:29:36 by akharfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_double( t_stack *doubl)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = doubl;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp1->nbr == tmp2->nbr)
				return (-1);
			tmp2 = tmp2 -> next;
		}
		tmp1 = tmp1->next;
	}
	return (0);
}

int	stack_sorted(t_stack *stack)
{
	if (stack == NULL)
		return (-1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (0);
		stack = stack->next;
	}
	return (-1);
}

static int	len_stack(t_stack *stack)
{
	int		len;
	t_stack	*current;

	len = 0;
	current = stack;
	while (current)
	{
		len++;
		current = current->next;
	}
	return (len);
}

void	ft_index_stack(t_stack *stack)
{
	t_stack	*current;
	t_stack	*compare;
	int		size;
	int		i;

	current = stack;
	size = len_stack(current);
	while (current)
	{
		i = 1;
		compare = stack;
		while (compare)
		{
			if (current->nbr > compare -> nbr)
				i++;
			compare = compare ->next;
		}
		current ->index = i;
		current = current ->next;
	}
}
