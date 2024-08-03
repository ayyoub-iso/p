/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharfat <akharfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:51:00 by akharfat          #+#    #+#             */
/*   Updated: 2024/08/02 17:55:10 by akharfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int			sign;
	long		number;
	long		res;

	(1) && (sign = 1, res = 0, number = 0);
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	if (!(*str >= '0' && *str <= '9'))
		ft_error();
	while (*str >= '0' && *str <= '9')
	{
		number = res * 10 + *str++ - 48;
		if (number < res || number * sign > 2147483647
			|| number * sign < -2147483648)
			ft_error();
		res = number;
	}
	(*str != '\0') && (ft_error(), res = 0);
	return (sign * number);
}

static t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next)
		lst = lst -> next;
	return (lst);
}

void	ft_add_back(t_stack **stack, t_stack *stack_new)
{
	if (!stack)
		return ;
	if (!*stack)
		*stack = stack_new;
	else
		(ft_lstlast(*stack))->next = stack_new;
}

t_stack	*ft_stack_new(int digit)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->nbr = digit;
	new->next = NULL;
	return (new);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
