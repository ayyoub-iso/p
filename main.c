/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharfat <akharfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 18:24:19 by akharfat          #+#    #+#             */
/*   Updated: 2024/08/03 12:15:04 by akharfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void f()
{
	system("leaks push_swap");
}
void	free_stack(t_stack *stack)
{
	t_stack	*temp;

	while (stack->next != NULL)
	{
		temp = stack->next;
		stack->next = temp->next;
		free(temp);
	}
	free(stack);
}

int	main(int argc, char **argv)
{
	atexit(f);
	t_stack	*a;
	t_stack	*b;			

	b = NULL;
	a = NULL;
	if (argc == 1)
		exit(EXIT_FAILURE);
	a = construction(argc, argv);
	if (ft_check_double(a) == -1)
	{
		write(2, "Error\n", 6);
		free_stack(a);
		exit (EXIT_FAILURE);
	}
	if (stack_sorted(a) == -1)
		return (free_stack(a), 0);
	ft_index_stack(a);
	sort (&a, b);
	return (free_stack(a), 0);
}
