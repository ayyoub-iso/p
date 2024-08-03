/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharfat <akharfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:36:57 by akharfat          #+#    #+#             */
/*   Updated: 2024/08/02 17:52:09 by akharfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	valid_characters(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!((str[i] == '-') || (str[i] == '+')
				|| (str[i] >= '0' && str[i] <= '9')
				|| (str[i] == 32)))
			return (-1);
		i++;
	}
	return (0);
}

static int	no_digit(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (-1);
}

t_stack	*construction(int argc, char **argv)
{
	t_stack	*a;
	char	**tmp;
	int		i;
	int		j;

	a = NULL;
	i = 1;
	while (i < argc)
	{
		if (valid_characters(argv[i]) == -1 || no_digit(argv[i]) == -1
			|| argv[i][0] == '\0' )
			ft_error();
		tmp = ft_split(argv[i], ' ');
		j = 0;
		while (tmp[j])
		{
			ft_add_back(&a, ft_stack_new(ft_atoi(tmp[j])));
			free(tmp[j]);
			j++;
		}
		free(tmp);
		i++;
	}
	return (a);
}
