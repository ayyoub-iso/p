/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharfat <akharfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:37:41 by akharfat          #+#    #+#             */
/*   Updated: 2024/08/02 18:49:17 by akharfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				nbr;
	int				index;
	struct s_stack	*next;
}	t_stack;

void	freeStack(t_stack *stack);
int		ft_atoi(const char *str);
t_stack	*construction(int argc, char **argv);
void	ft_add_back(t_stack **stack, t_stack *stack_new);
t_stack	*ft_stack_new(int digit);
void	ft_error(void);
char	**ft_split(const char *str, char spliter);
void	ft_index_stack(t_stack *stack);
void	swap(t_stack **stack);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	push(t_stack **stack_from, t_stack **stack_to);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);
void	rotate(t_stack **stack);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	reverse_rotate(t_stack **stack);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	alg_tree(t_stack **a);
void	alg_four(t_stack **a, t_stack **b);
void	alg_five(t_stack **a, t_stack **b);
int		stack_len(t_stack *stack);
int		stack_sorted(t_stack *stack);
int		ft_check_double( t_stack *doubl);
void	sort_push_b(t_stack **a, t_stack **b);
void	sort_push_a(t_stack **a, t_stack **b);
void	algo(t_stack **a, t_stack **b);
void	sort(t_stack **a, t_stack *b);
size_t	ft_strlen(const char *s);
t_stack	*find_smallest(t_stack *stack);
#endif
